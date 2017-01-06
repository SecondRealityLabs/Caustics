#pragma once

#include "Texture2D.h"

class CubeMap
{

	private:

		Texture2D negX;
		Texture2D negY;
		Texture2D negZ;
			   
		Texture2D posX;
		Texture2D posY;
		Texture2D posZ;

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

