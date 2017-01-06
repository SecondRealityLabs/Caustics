//#pragma once
//
////#include "GL/freeglut.h"
//#include "SOIL.h"
//
//class Texture
//{
//
//	private:
//
//		int height, width;
//		int type;
//		int channels;
//
//		unsigned char* data;
//
//		GLuint texID;
//
//	public:
//	
//		Texture();
//		~Texture();
//
//		bool load(char* path);
//		bool save(char* path);
//
//};
//
//
//
//
#pragma once


class Texture
{
public:
	Texture();
	~Texture();
	std::string Name;

	virtual bool Load() = 0;
	void Bind(GLenum textureUnit);
	void Unbind();

protected:
	GLenum TextureTarget;
	GLuint TextureHandle;
};

