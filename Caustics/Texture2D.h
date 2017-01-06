#pragma once
#include "Texture.h"
#include <string>
#include <glew.h>

class Texture2D : public Texture
{
public:
	Texture2D(const std::string& DirName, const std::string& FileName, GLenum TextureTarget = GL_TEXTURE_2D);
	Texture2D();
	~Texture2D();
	bool Load() override;

private:
	std::string FileName;
	std::string DirName;
};

