#include "stdafx.h"
#include "Shader.h"

Shader::Shader()
{
	noOfFS = 0;
	noOfGS = 0;
	noOfVS = 0;
}

Shader::~Shader()
{

}

bool Shader::addFS(int id, char * path)
{

	FILE* f;
	GLchar* data;
	GLuint size;
	GLuint object;

		f = fopen(path, "rb");
		
		fseek(f, 0, SEEK_END);		

		size = ftell(f);

		rewind(f);

		data = (GLchar*)malloc(size);

		fragSizes.push_back(size);

		fread(data, 1, fragSizes.at(id), f);

		fclose(f);

		fragDatas.push_back(data);

		fragSizes.push_back(size);

		fragObjects.push_back(object);

		noOfFS++;
		
	return (false);

}

bool Shader::addGS(int id, char * path)
{

	FILE* f;

	GLchar* data;
	GLuint size;
	GLuint object;

		f = fopen(path, "rb");

		fseek(f, 0, SEEK_END);

		size = ftell(f);

		rewind(f);

		data = (GLchar*)malloc(size);

		geomSizes.push_back(size);

		fread(data, 1, geomSizes.at(id), f);

		fclose(f);

		geomDatas.push_back(data);

		geomSizes.push_back(size);

		geomObjects.push_back(object);

		noOfGS++;
		
	return (false);

}

bool Shader::addVS(int id, char* path)
{

	FILE* f;

	GLchar* data;
	GLuint size;
	GLuint object;

		f = fopen(path, "rb");

		fseek(f, 0, SEEK_END);

		size = ftell(f);

		rewind(f);

		data = (GLchar*)malloc(size);

		vertSizes.push_back(size);

		fread(data, 1, vertSizes.at(id), f);

		fclose(f);

		vertDatas.push_back(data);

		vertSizes.push_back(size);

		vertObjects.push_back(object);

		noOfVS++;
		
	return (false);

}

bool Shader::compileFS(int id) 
{

	GLint Success;
	
		program = glCreateProgram();

		if (program == 0)
		{
			fprintf(stderr, "Error creating shader program\n");
			_getch();


			exit(1);
		}
	
		fragObjects.at(id) = glCreateShader(GL_FRAGMENT_SHADER);

		if (fragObjects.at(id) == 0) 
		{
			fprintf(stderr, "Error creating shader type %d\n", GL_FRAGMENT_SHADER);

			exit(0);
		}
		 
		glShaderSource(fragObjects.at(id), 1, &fragDatas.at(id), &fragSizes.at(id));
		glCompileShader(fragObjects.at(id));
		glGetShaderiv(fragObjects.at(id), GL_COMPILE_STATUS, &Success);

		if (!Success) 
		{
			glGetShaderInfoLog(fragObjects.at(id), 1024, NULL, compileLog);
			fprintf(stderr, "Error compiling shader type %d: '%s'\n", GL_FRAGMENT_SHADER, compileLog);

			printLogs();
			_getch();

			exit(1);
		}

		glAttachShader(program, fragObjects.at(id));

	return false;

}

bool Shader::compileGS(int id)
{

	GLint Success;

		program = glCreateProgram();

		if (program == 0)
		{
			fprintf(stderr, "Error creating shader program\n");
			_getch();
			exit(1);
		}
	
		geomObjects.at(id) = glCreateShader(GL_GEOMETRY_SHADER);

		if (geomObjects.at(id) == 0)
		{
			fprintf(stderr, "Error creating shader type %d\n", GL_GEOMETRY_SHADER);
			exit(0);
		}

		glShaderSource(geomObjects.at(id), 1, &geomDatas.at(id), &geomSizes.at(id));
		glCompileShader(geomObjects.at(id));
		glGetShaderiv(geomObjects.at(id), GL_COMPILE_STATUS, &Success);

		if (!Success)
		{
			glGetShaderInfoLog(geomObjects.at(id), 1024, NULL, compileLog);
			fprintf(stderr, "Error compiling shader type %d: '%s'\n", GL_GEOMETRY_SHADER, compileLog);
			
			printLogs();
			_getch();

			exit(1);
		}

		glAttachShader(program, geomObjects.at(id));

	return false;

}

bool Shader::compileVS(int id)
{

	GLint Success;

		program = glCreateProgram();

		if (program == 0)
		{
			fprintf(stderr, "Error creating shader program\n");
			_getch();
			exit(1);
		}
	
		vertObjects.at(id) = glCreateShader(GL_VERTEX_SHADER);

		if (vertObjects.at(id) == 0)
		{
			fprintf(stderr, "Error creating shader type %d\n", GL_VERTEX_SHADER);
			_getch();
			
			exit(0);
		}

		glShaderSource(vertObjects.at(id), 1, &vertDatas.at(id), &vertSizes.at(id));
		glCompileShader(vertObjects.at(id));
		glGetShaderiv(vertObjects.at(id), GL_COMPILE_STATUS, &Success);

		if (!Success)
		{
			glGetShaderInfoLog(vertObjects.at(id), 1024, NULL, compileLog);
			fprintf(stderr, "Error compiling shader type %d: '%s'\n", GL_VERTEX_SHADER, compileLog);

			printLogs();
			_getch();

			exit(1);
		}

		glAttachShader(program, vertObjects.at(id));

	return false;

}

bool Shader::linkFS(int id)
{

	GLint Success = 0;

		glLinkProgram(program);
		glGetProgramiv(program, GL_LINK_STATUS, &Success);

		if (Success == 0) 
		{
			glGetProgramInfoLog(program, sizeof(linkLog), NULL, linkLog);
			fprintf(stderr, "Error linking shader program: '%s'\n", linkLog);

			printLogs();
			_getch();

			exit(1);
		}

		glValidateProgram(program);
		glGetProgramiv(program, GL_VALIDATE_STATUS, &Success);
		
		if (!Success) 
		{
			glGetProgramInfoLog(program, sizeof(linkLog), NULL, linkLog);
			fprintf(stderr, "Invalid shader program: '%s'\n", linkLog);

			printLogs();
			_getch();

			exit(1);
		}

		glUseProgram(program);

	return false;

}

bool Shader::linkGS(int id)
{

	GLint Success = 0;

		glLinkProgram(program);
		glGetProgramiv(program, GL_LINK_STATUS, &Success);

		if (Success == 0)
		{
			glGetProgramInfoLog(program, sizeof(linkLog), NULL, linkLog);
			fprintf(stderr, "Error linking shader program: '%s'\n", linkLog);

			printLogs();
			_getch();

			exit(1);
		}

		glValidateProgram(program);
		glGetProgramiv(program, GL_VALIDATE_STATUS, &Success);

		if (!Success)
		{
			glGetProgramInfoLog(program, sizeof(linkLog), NULL, linkLog);
			fprintf(stderr, "Invalid shader program: '%s'\n", linkLog);

			printLogs();
			_getch();

			exit(1);
		}

		glUseProgram(program);

	return false;

}

bool Shader::linkVS(int id)
{

	GLint Success = 0;

		glLinkProgram(program);
		glGetProgramiv(program, GL_LINK_STATUS, &Success);

		if (Success == 0)
		{
			glGetProgramInfoLog(program, sizeof(linkLog), NULL, linkLog);
			fprintf(stderr, "Error linking shader program: '%s'\n", linkLog);

			printLogs();
			_getch();

			exit(1);
		}

		glValidateProgram(program);
		glGetProgramiv(program, GL_VALIDATE_STATUS, &Success);

		if (!Success)
		{
			glGetProgramInfoLog(program, sizeof(linkLog), NULL, linkLog);
			fprintf(stderr, "Invalid shader program: '%s'\n", linkLog);

			printLogs();
			_getch();

			exit(1);
		}

		glUseProgram(program);

	return false;

}

bool Shader::compile()
{

	int i;

		for (i = 0; i < noOfFS; i++)
			compileFS(i);

		for (i = 0; i < noOfGS; i++)
			compileGS(i);

		for (i = 0; i < noOfVS; i++)
			compileVS(i);

	return (false);

}

bool Shader::link()
{

	int i;
	
		for (i = 0; i < noOfFS; i++)
			linkFS(i);

		for (i = 0; i < noOfGS; i++)
			linkGS(i);

		for (i = 0; i < noOfVS; i++)
			linkVS(i);

	return (false);

}

bool Shader::printLogs()
{

		printf("%s \n", compileLog);
		printf("%s \n", linkLog);
	
	return false;

}

bool Shader::unprintLogs()
{

		
		

	return false;

}

void Shader::addShader(GLuint ShaderProgram, const char* pShaderText, GLenum ShaderType)
{
	GLuint ShaderObj = glCreateShader(ShaderType);

	if (ShaderObj == 0)
	{
		fprintf(stderr, "Error creating shader type %d\n", ShaderType);
		exit(0);
	}

	const GLchar* p[1];
	p[0] = pShaderText;
	GLint Lengths[1];
	Lengths[0] = strlen(pShaderText);
	glShaderSource(ShaderObj, 1, p, Lengths);
	glCompileShader(ShaderObj);
	GLint success;
	glGetShaderiv(ShaderObj, GL_COMPILE_STATUS, &success);

	if (!success) {
		GLchar InfoLog[1024];
		glGetShaderInfoLog(ShaderObj, 1024, NULL, InfoLog);
		fprintf(stderr, "Error compiling shader type %d: '%s'\n", ShaderType, InfoLog);
		exit(1);
	}

	glAttachShader(ShaderProgram, ShaderObj);
}

GLuint Shader::compileShaders(char* fragShader, char* vertShader)
{
	GLuint ShaderProgram = glCreateProgram();
	GLuint vertexShaderObj = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShaderObj = glCreateShader(GL_FRAGMENT_SHADER);

	string vertexShaderText;
	string fragmentShaderText;
	const GLchar* fs, *vs;
	const char* vsFileName = "Shaders/Caustic.vs.glsl";
	const char* fsFileName = "Shaders/Caustic.fs.glsl";

	Shader::readFile(vsFileName, vertexShaderText);
	Shader::readFile(fsFileName, fragmentShaderText);
	vs = vertexShaderText.c_str();
	fs = fragmentShaderText.c_str();

	GLint Lengths[2];
	Lengths[0] = strlen(vertexShaderText.c_str());
	Lengths[1] = strlen(fragmentShaderText.c_str());

	glShaderSource(vertexShaderObj, 1, &vs, &Lengths[0]);
	glShaderSource(fragmentShaderObj, 1, &fs, &Lengths[1]);

	glCompileShader(vertexShaderObj);
	glCompileShader(fragmentShaderObj);

	GLint success;
	glGetShaderiv(vertexShaderObj, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		GLchar InfoLog[1024];
		glGetShaderInfoLog(vertexShaderObj, sizeof(InfoLog), NULL, InfoLog);
		fprintf(stderr, "Error compiling shader type %d: '%s'\n", GL_VERTEX_SHADER, InfoLog);
	}

	glGetShaderiv(fragmentShaderObj, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		GLchar InfoLog[1024];
		glGetShaderInfoLog(fragmentShaderObj, sizeof(InfoLog), NULL, InfoLog);
		fprintf(stderr, "Error compiling shader type %d: '%s'\n", GL_FRAGMENT_SHADER, InfoLog);
	}

	glAttachShader(ShaderProgram, vertexShaderObj);
	glAttachShader(ShaderProgram, fragmentShaderObj);
	glLinkProgram(ShaderProgram);

	glDeleteShader(vertexShaderObj);
	glDetachShader(ShaderProgram, vertexShaderObj);
	glDeleteShader(fragmentShaderObj);
	glDetachShader(ShaderProgram, fragmentShaderObj);

	int Success;
	glGetProgramiv(ShaderProgram, GL_LINK_STATUS, &Success);
	if (Success == 0)
	{
		GLchar ErrorLog[1024];
		glGetProgramInfoLog(ShaderProgram, sizeof(ErrorLog), NULL, ErrorLog);
		fprintf(stderr, "Error linking shader program: '%s'\n", ErrorLog);
	}
	glValidateProgram(ShaderProgram);
	glUseProgram(ShaderProgram);


	return ShaderProgram;
}

bool Shader::readFile(const char* pFileName, string& outFile)
{
	ifstream f(pFileName);

	bool ret = false;

	if (f.is_open()) {
		string line;
		while (getline(f, line)) {
			outFile.append(line);
			outFile.append("\n");
		}

		f.close();

		ret = true;
	}
	else
	{
		//OGLDEV_FILE_ERROR(pFileName);
	}

	return ret;
}



