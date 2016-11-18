#pragma once

#include "Texture.h"

class CubeMap
{

	private:

		Texture negX;
		Texture negY;
		Texture negZ;

		Texture posX;
		Texture posY;
		Texture posZ;

	public:
	
		CubeMap();
		~CubeMap();

		bool loadNegX(char* path);
		bool loadNegY(char* path);
		bool loadNegZ(char* path);

		bool loadPosX(char* path);
		bool loadPosY(char* path);
		bool loadPosZ(char* path);

		bool saveNegX(char* path);
		bool saveNegY(char* path);
		bool saveNegZ(char* path);

		bool savePosX(char* path);
		bool savePosY(char* path);
		bool savePosZ(char* path);

};

