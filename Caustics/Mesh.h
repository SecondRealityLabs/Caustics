#pragma once
#include "stdafx.h"
#include "Texture.h"

struct aiMesh;
struct aiScene;
struct aiTexture;
struct Vertex;

class Mesh
{

public:
	Mesh();
	~Mesh();

	void render();
	bool load(const std::string& Dirname, const std::string& Filename);
	void setTextures(const std::string& Dirname, std::vector<std::string> texturesFileNames);

private:
	bool initFromScene(const aiScene* pScene, const std::string& Dirname);
	void initMesh(unsigned int Index, const aiMesh* paiMesh);
	bool initMaterials(const aiScene* pScene, const std::string& Filename);

	std::vector<Vertex> Vertices;

	struct MeshEntry
	{
		MeshEntry();

		~MeshEntry();

		void init(const std::vector<Vertex>& Vertices, const std::vector<unsigned int>& Indices);

		GLuint VB;
		GLuint IB;
		unsigned int NumIndices;
		unsigned int MaterialIndex;
	};

	std::vector<MeshEntry> Entries;
	std::vector<Texture*> Textures;

};

struct Vertex
{
	vec3 Position;
	vec2 Texture;
	vec3 Normals;

	Vertex() {}

	Vertex(const vec3& pos, const vec2& tex, const vec3& normal)
	{
		Position = pos;
		Texture = tex;
		Normals = normal;
	}

};