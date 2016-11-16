#include "stdafx.h"
#include "Texture.h"


Texture::Texture()
{
}


Texture::~Texture()
{
}

bool Texture::load(char * path)
{

	bool ret;
	
		/* load OpenGL texture */
		texID = SOIL_load_OGL_texture
		(
			path,
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_INVERT_Y
		);

		/* check if texture is OK */
		if (texID == 0)
			return false;

		/* texture generation */
		glBindTexture(GL_TEXTURE_2D, texID);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glBindTexture(GL_TEXTURE_2D, NULL);

	return true;

}

bool Texture::save(char * path)
{

	bool ret;

		SOIL_save_image
		(

			path,
			type,
			width,
			height,
			channels,
			data

		);


	return false;

}
