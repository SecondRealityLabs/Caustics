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

