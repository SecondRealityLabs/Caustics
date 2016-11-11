#pragma once

#include <vector>

#include "Mesh.h"
#include "Texture.h"

class Model
{

	private:

		std::vector<Mesh> meshes;
		std::vector<Texture> textures;


	public:
	
		Model();
		~Model();

		void addMesh(void);
		void delMesh(void);

		void addTexture(void);
		void delTexture(void);


};

