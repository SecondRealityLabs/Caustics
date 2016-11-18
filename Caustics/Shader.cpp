#include "stdafx.h"
#include "Shader.h"

Shader::Shader()
{
	fragData = nullptr;
}

Shader::~Shader()
{
	delete fragData;
}

bool Shader::loadFS(char * path)
{

	FILE* f;

	f = fopen(path, "rb");

	fseek(f, 0, SEEK_END);

	fragSize = ftell(f);

	fread(fragData, 1, fragSize, f);

	fclose(f);

	return (false);

}

bool Shader::loadGS(char * path)
{

	FILE* f;

	f = fopen(path, "rb");

	fseek(f, 0, SEEK_END);

	fragSize = ftell(f);

	fread(fragData, 1, fragSize, f);

	fclose(f);

	return (false);

}

bool Shader::loadVS(char* path)
{

	FILE* f;

	f = fopen(path, "rb");

	fseek(f, 0, SEEK_END);

	fragSize = ftell(f);

	fread(fragData, 1, fragSize, f);

	fclose(f);

	return (false);

}

bool Shader::compileFS(void)
{

	GLint Success;

	fragObject = glCreateShader(GL_FRAGMENT_SHADER);

	if (fragObject == 0)
	{
		fprintf(stderr, "Error creating shader type %d\n", GL_FRAGMENT_SHADER);
		exit(0);
	}

	glShaderSource(fragObject, 1, &fragData, &fragSize);
	glCompileShader(fragObject);
	glGetShaderiv(fragObject, GL_COMPILE_STATUS, &Success);

	if (!Success)
	{
		glGetShaderInfoLog(fragObject, 1024, NULL, infoLog);
		fprintf(stderr, "Error compiling shader type %d: '%s'\n", GL_FRAGMENT_SHADER, infoLog);
		exit(1);
	}

	glAttachShader(fragProgram, fragObject);

	return false;

}

bool Shader::compileGS(void)
{

	GLint Success;

	geomObject = glCreateShader(GL_GEOMETRY_SHADER);

	if (geomObject == 0)
	{
		fprintf(stderr, "Error creating shader type %d\n", GL_GEOMETRY_SHADER);
		exit(0);
	}

	glShaderSource(geomObject, 1, &geomData, &geomSize);
	glCompileShader(geomObject);
	glGetShaderiv(geomObject, GL_COMPILE_STATUS, &Success);

	if (!Success)
	{
		glGetShaderInfoLog(geomObject, 1024, NULL, infoLog);
		fprintf(stderr, "Error compiling shader type %d: '%s'\n", GL_GEOMETRY_SHADER, infoLog);
		exit(1);
	}

	glAttachShader(geomProgram, geomObject);

	return false;

}

bool Shader::compileVS(void)
{

	GLint Success;

	vertObject = glCreateShader(GL_VERTEX_SHADER);

	if (vertObject == 0)
	{
		fprintf(stderr, "Error creating shader type %d\n", GL_VERTEX_SHADER);
		exit(0);
	}

	glShaderSource(vertObject, 1, &vertData, &vertSize);
	glCompileShader(vertObject);
	glGetShaderiv(vertObject, GL_COMPILE_STATUS, &Success);

	if (!Success)
	{
		glGetShaderInfoLog(vertObject, 1024, NULL, infoLog);
		fprintf(stderr, "Error compiling shader type %d: '%s'\n", GL_VERTEX_SHADER, infoLog);
		exit(1);
	}

	glAttachShader(vertProgram, vertObject);

	return false;

}

bool Shader::linkFS(void)
{

	GLint Success = 0;

	glLinkProgram(fragProgram);
	glGetProgramiv(fragProgram, GL_LINK_STATUS, &Success);

	if (Success == 0)
	{
		glGetProgramInfoLog(fragProgram, sizeof(errorLog), NULL, errorLog);
		fprintf(stderr, "Error linking shader program: '%s'\n", errorLog);
		exit(1);
	}

	glValidateProgram(fragProgram);
	glGetProgramiv(fragProgram, GL_VALIDATE_STATUS, &Success);

	if (!Success)
	{
		glGetProgramInfoLog(fragProgram, sizeof(errorLog), NULL, errorLog);
		fprintf(stderr, "Invalid shader program: '%s'\n", errorLog);
		exit(1);
	}

	glUseProgram(fragProgram);

	return false;

}

bool Shader::linkGS(void)
{

	GLint Success = 0;

	glLinkProgram(geomProgram);
	glGetProgramiv(geomProgram, GL_LINK_STATUS, &Success);


	if (Success == 0)
	{
		glGetProgramInfoLog(geomProgram, sizeof(errorLog), NULL, errorLog);
		fprintf(stderr, "Error linking shader program: '%s'\n", errorLog);
		exit(1);
	}

	glValidateProgram(geomProgram);
	glGetProgramiv(geomProgram, GL_VALIDATE_STATUS, &Success);

	if (!Success)
	{
		glGetProgramInfoLog(geomProgram, sizeof(errorLog), NULL, errorLog);
		fprintf(stderr, "Invalid shader program: '%s'\n", errorLog);
		exit(1);
	}

	glUseProgram(geomProgram);

	return false;

}

bool Shader::linkVS(void)
{

	GLint Success = 0;

	glLinkProgram(vertProgram);
	glGetProgramiv(vertProgram, GL_LINK_STATUS, &Success);

	if (Success == 0)
	{
		glGetProgramInfoLog(vertProgram, sizeof(errorLog), NULL, errorLog);
		fprintf(stderr, "Error linking shader program: '%s'\n", errorLog);
		exit(1);
	}

	glValidateProgram(vertProgram);
	glGetProgramiv(vertProgram, GL_VALIDATE_STATUS, &Success);

	if (!Success)
	{
		glGetProgramInfoLog(vertProgram, sizeof(errorLog), NULL, errorLog);
		fprintf(stderr, "Invalid shader program: '%s'\n", errorLog);
		exit(1);
	}

	glUseProgram(vertProgram);

	return false;

}







