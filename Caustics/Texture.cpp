//#include "stdafx.h"
//#include "Texture.h"
//
//
//Texture::Texture()
//{
//}
//
//
//Texture::~Texture()
//{
//}
//
//bool Texture::load(char * path)
//{
//
//	bool ret;
//	
//		ret = false;
//	
//		/* load OpenGL texture */
//		texID = SOIL_load_OGL_texture
//		(
//			path,
//			SOIL_LOAD_AUTO,
//			SOIL_CREATE_NEW_ID,
//			SOIL_FLAG_INVERT_Y
//		);
//
//		/* check if texture is OK */
//		if (texID == 0)
//			return false;
//
//		/* texture generation */
//		glBindTexture(GL_TEXTURE_2D, texID);
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//		glBindTexture(GL_TEXTURE_2D, NULL);
//
//	return (ret);
//
//}
//
//bool Texture::save(char * path)
//{
//
//	bool ret;
//
//		ret = false;
//
//		SOIL_save_image
//		(
//
//			path,
//			type,
//			width,
//			height,
//			channels,
//			data
//
//		);
//
//
//	return (ret);
//
//}

#include "stdafx.h"
#include "Texture.h"
#include <SOIL.h>


Texture::Texture()
{}

Texture::~Texture()
{
	if (TextureHandle != 0)
		glDeleteTextures(1, &TextureHandle);
}

bool Texture::Load()
{
	return true;
}

void Texture::Bind(GLenum textureUnit)
{
	glActiveTexture(textureUnit);
	glBindTexture(TextureTarget, TextureHandle);
}

void Texture::Unbind()
{
	glBindTexture(TextureTarget, 0);
}
