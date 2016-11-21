#pragma once

#include <vector>

#include "Shader.h"

#include "Camera.h"
#include "Light.h"
#include "Model.h"

class Scene
{

	private:

		long noOfCameras;
		long noOfLights;
		long noOfModels;
		long noOfShaders;

		std::vector<Camera> cameras;
		std::vector<Light> lights;
		std::vector<Model> models;
		std::vector<Shader> shaders;

	public:
	
		Scene();
		~Scene();

		bool init(void);
		bool shut(void);

		bool addCamera(Camera *camera);
		bool addCamera(const char* path);
		bool delCamera(Camera *camera);
		bool delCamera(const char* path);

		bool addLight(Light *light);
		bool addLight(const char* path);
		bool delLight(Light *light);
		bool delLight(const char* path);

		bool addModel(Model *model);
		bool addModel(const char* path);
		bool delModel(Model *model);
		bool delModel(const char* path);

		bool addShader(Shader *shader);
		bool addShader(char* fsPath, char* vsPath);
		bool delShader(Shader *shader);
		bool delShader(char* fsPath, char* vsPath);

		bool addAmbLight(float x, float y, float z);
		bool addDirLight(float x, float y, float z);
		bool addSpotLight(float x, float y, float z);

		bool delAmbLight(float x, float y, float z);
		bool delDirLight(float x, float y, float z);
		bool delSpotLight(float x, float y, float z);

		void setSkyNegX(const char* path);
		void setSkyNegY(const char* path);
		void setSkyNegZ(const char* path);
		void setSkyPosX(const char* path);
		void setSkyPosY(const char* path);
		void setSkyPosZ(const char* path);

		void setWaterNegX(const char* path);
		void setWaterNegY(const char* path);
		void setWaterNegZ(const char* path);
		void setWaterPosX(const char* path);
		void setWaterPosY(const char* path);
		void setWaterPosZ(const char* path);

		void updCamera(void);
		void updLights(void);
		void updModels(void);
		void updShaders(void);
		void updWater(void);
		void updSky(void);

		void render(void);
		void vsync(void);

};

