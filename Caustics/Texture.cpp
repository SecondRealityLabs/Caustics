#include "stdafx.h"
#include "Texture.h"


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
