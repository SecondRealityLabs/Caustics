#pragma once
#include <SOIL.h>

class Texture
{

	private:

		int height, width;
		int type;
		int channels;

		unsigned char* data;

		GLuint texID;

	public:
	
		Texture();
		~Texture();

		bool load(char* path);
		bool save(char* path);

};




