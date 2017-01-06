#include "stdafx.h"
#include "Texture2D.h"
#include <SOIL.h>


Texture2D::Texture2D(const std::string& DirName, const std::string& FileName, GLenum TextureTarget)
{
	std::string tmpFileName = FileName;
	char let;
	while ((let = tmpFileName[tmpFileName.size() - 1]) != '.')
	{
		tmpFileName.pop_back();
	}
	tmpFileName.pop_back();

	this->TextureTarget = TextureTarget;
	this->FileName = FileName;
	this->DirName = DirName;
	this->Name = tmpFileName;
}

Texture2D::Texture2D()
{	
}

bool Texture2D::Load()
{
	TextureHandle = SOIL_load_OGL_texture
	(
		(DirName + FileName).c_str(),
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	//| SOIL_FLAG_INVERT_Y
	if (0 == TextureHandle)
	{
		printf("SOIL loading error: '%s'\n", SOIL_last_result());
		return false;
	}

	glBindTexture(TextureTarget, TextureHandle);

	glTexParameterf(TextureTarget, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameterf(TextureTarget, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);


	return true;
}


Texture2D::~Texture2D()
{}
