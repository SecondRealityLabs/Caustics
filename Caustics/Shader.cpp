#include "stdafx.h"
#include "Shader.h"


Shader::Shader()
{
}


Shader::~Shader()
{
}

bool Shader::compileGS(void)
{

	//static void AddShader(GLuint ShaderProgram, const char* pShaderText, GLenum ShaderType)
	//{
	//	GLuint ShaderObj = glCreateShader(ShaderType);

	//	if (ShaderObj == 0) {
	//		fprintf(stderr, "Error creating shader type %d\n", ShaderType);
	//		exit(0);
	//	}

	//	const GLchar* p[1];
	//	p[0] = pShaderText;
	//	GLint Lengths[1];
	//	Lengths[0] = strlen(pShaderText);
	//	glShaderSource(ShaderObj, 1, p, Lengths);
	//	glCompileShader(ShaderObj);
	//	GLint success;
	//	glGetShaderiv(ShaderObj, GL_COMPILE_STATUS, &success);
	//	if (!success) {
	//		GLchar InfoLog[1024];
	//		glGetShaderInfoLog(ShaderObj, 1024, NULL, InfoLog);
	//		fprintf(stderr, "Error compiling shader type %d: '%s'\n", ShaderType, InfoLog);
	//		exit(1);
	//	}

	//	glAttachShader(ShaderProgram, ShaderObj);
	//}






	return false;
}

bool Shader::add(GLuint program, const char * text, GLenum type)
{


	//GLuint ShaderProgram, const char* pShaderText, GLenum ShaderType








	return false;
}
