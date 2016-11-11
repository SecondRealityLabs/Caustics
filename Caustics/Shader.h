#pragma once

#include <string>

class Shader
{

	private:
		
		bool areCompiled;											// are shaders compiled?
		bool areLinked;												// is shader linked?

		char* fragName;												// fragment shader name
		char* geomName;												// geometry shader name
		char* hullName;												// hull shader name
		char* tessName;												// tessalation shader name
		char* vertName;												// vertex shader name

		std::string fragShader;										// fragment shader
		std::string geomShader;										// geometry shader
		std::string hullShader;										// hull shader
		std::string tessShader;										// tessaltion shader
		std::string vertShader;										// vertex shader

	public:
	
		Shader();													// shader constructor
		~Shader();													// shader detructor

		bool loadFS(char* path);									// load fragment shader
		bool saveFS(char* path);									// save fragment shader

		bool loadGS(char* path);									// load geometry shader
		bool saveGS(char* path);									// save geometry shader

		bool loadHS(char* path);									// load hull shader
		bool saveHS(char* path);									// save hull shader

		bool loadTS(char* path);									// load tessalate shader
		bool saveTS(char* path);									// save tessalate shader
			
		bool loadVS(char* path);									// load vertex shader
		bool saveVS(char* path);									// save vertex shader

		bool compileFS(void);										// compile fragment shader
		bool compileGS(void);										// compile geometry shader
		bool compileHS(void);										// compile hull shader
		bool compileTS(void);										// compile tessalate shader
		bool compileVS(void);										// compile vertex shader

		bool linkFS(void);											// link fragment shader
		bool linkGS(void);											// link geometry shader
		bool linkHS(void);											// link hull shader
		bool linkTS(void);											// link tessalate shader
		bool linkVS(void);											// link vertex shader

		bool add(GLuint program, const char* text, GLenum type);	// add program shader	
		bool del(GLuint program, const char* text, GLenum type);	// del program shader

};

