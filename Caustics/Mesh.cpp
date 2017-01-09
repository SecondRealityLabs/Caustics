#include "stdafx.h"
#include "Mesh.h"
#include <Importer.hpp>
#include <postprocess.h>
#include <scene.h>
#include <texture.h>
#include "Texture2D.h"

Mesh::Mesh()
{
}


Mesh::~Mesh()
{
}

void Mesh::render()
{
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	for (unsigned int i = 0; i < Entries.size(); i++)
	{
		glBindBuffer(GL_ARRAY_BUFFER, Entries[i].VB);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);  //0: strumien pozycji
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid*)12); //12 = float * 3 //1: strumien uv
		glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid*)20); //20 = 12 + float * 2 //2: strumien normalek

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Entries[i].IB);

		const unsigned int MaterialIndex = Entries[i].MaterialIndex;

		if (MaterialIndex < Textures.size() && Textures[MaterialIndex])
		{
			Textures[MaterialIndex]->Bind(GL_TEXTURE0);
		}

		glDrawElements(GL_TRIANGLES, Entries[i].NumIndices, GL_UNSIGNED_INT, 0);
	}

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
}

bool Mesh::load(const std::string& Dirname, const std::string& Filename)
{
	bool Ret = false;
	Assimp::Importer Importer;

	const aiScene* pScene = Importer.ReadFile(Dirname+ "\\"+Filename.c_str(), aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_FlipUVs);

	if (pScene)
	{
		Ret = initFromScene(pScene, Dirname);
	}
	else
	{
		printf("Error parsing '%s': '%s'\n", Filename.c_str(), Importer.GetErrorString());
	}

	return Ret;
}

void Mesh::setTextures(const std::string& Dirname, std::vector<std::string> textureFileNames)
{
	Textures.clear();

	for (int i = 0; i < textureFileNames.size(); i++)
	{
		Textures.push_back(new Texture2D(Dirname, textureFileNames[i]));
		Textures[i]->Load();
	}
}

bool Mesh::initFromScene(const aiScene* pScene, const std::string& Dirname)
{
	Entries.resize(pScene->mNumMeshes);
	Textures.resize(pScene->mNumMaterials);

	// Initialize the meshes in the scene one by one
	for (unsigned int i = 0; i < Entries.size(); i++)
	{
		const aiMesh* paiMesh = pScene->mMeshes[i];
		initMesh(i, paiMesh);
	}

	return initMaterials(pScene, Dirname);
}

void Mesh::initMesh(unsigned int Index, const aiMesh* paiMesh)
{
	Entries[Index].MaterialIndex = paiMesh->mMaterialIndex;

	std::vector<Vertex> Vertices;
	std::vector<unsigned int> Indices;

	const aiVector3D Zero3D(0.0f, 0.0f, 0.0f);

	for (unsigned int i = 0; i < paiMesh->mNumVertices; i++)
	{
		const aiVector3D* pPos = &(paiMesh->mVertices[i]);
		const aiVector3D* pNormal = &(paiMesh->mNormals[i]);
		const aiVector3D* pTexCoord = paiMesh->HasTextureCoords(0) ? &(paiMesh->mTextureCoords[0][i]) : &Zero3D;

		Vertex v(vec3(pPos->x, pPos->y, pPos->z),
			vec2(pTexCoord->x, pTexCoord->y),
			vec3(pNormal->x, pNormal->y, pNormal->z));

		Vertices.push_back(v);
	}

	for (unsigned int i = 0; i < paiMesh->mNumFaces; i++)
	{
		const aiFace& Face = paiMesh->mFaces[i];
		assert(Face.mNumIndices == 3);
		Indices.push_back(Face.mIndices[0]);
		Indices.push_back(Face.mIndices[1]);
		Indices.push_back(Face.mIndices[2]);
	}

	Entries[Index].init(Vertices, Indices);
}

bool Mesh::initMaterials(const aiScene* pScene, const std::string& Dirname)
{
	bool Ret = false;

	for (unsigned int i = 0; i < pScene->mNumMaterials; i++)
	{
		const aiMaterial* pMaterial = pScene->mMaterials[i];
		Textures[i] = NULL;
		if (pMaterial->GetTextureCount(aiTextureType_DIFFUSE) > 0)
		{
			aiString Path;

			if (pMaterial->GetTexture(aiTextureType_DIFFUSE, 0, &Path, NULL, NULL, NULL, NULL, NULL) == AI_SUCCESS)
			{
				Textures[i] = new Texture2D(Dirname, Path.data);

				if (!Textures[i]->Load())
				{
					printf("Error loading texture '%s'\n", Path.data);
					delete Textures[i];
					Textures[i] = NULL;
					Ret = false;
				}
			}
		}

		if (!Textures[i])
		{
			Textures[i] = new Texture2D(Dirname, "/txt-subm-1.jpg");    // do zmiany
			Ret = Textures[i]->Load();
		}
	}

	return Ret;
}

Mesh::MeshEntry::MeshEntry()
{
	VB = GL_INVALID_INDEX;
	IB = GL_INVALID_INDEX;
	NumIndices = 0;
	MaterialIndex = GL_INVALID_INDEX;
}

Mesh::MeshEntry::~MeshEntry()
{
	if (VB != GL_INVALID_INDEX)
	{
		glDeleteBuffers(1, &VB);
	}

	if (IB != GL_INVALID_INDEX)
	{
		glDeleteBuffers(1, &IB);
	}
}

void Mesh::MeshEntry::init(const std::vector<Vertex>& Vertices, const std::vector<unsigned int>& Indices)
{
	NumIndices = Indices.size();

	glGenBuffers(1, &VB);
	glBindBuffer(GL_ARRAY_BUFFER, VB);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * Vertices.size(), &Vertices[0], GL_STATIC_DRAW);

	glGenBuffers(1, &IB);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IB);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * NumIndices, &Indices[0], GL_STATIC_DRAW);
}