#include "stdafx.h"
#include "Scene.h"

Scene::Scene()
{
}

Scene::~Scene()
{
}

bool Scene::init(void)
{
	return false;
}

bool Scene::shut(void)
{
	return false;
}

bool Scene::addCamera(Camera * camera)
{
	return false;
}

bool Scene::addCamera(const char * path)
{
	return false;
}

bool Scene::delCamera(Camera * camera)
{
	return false;
}

bool Scene::delCamera(const char * path)
{
	return false;
}

bool Scene::addLight(Light * light)
{
	return false;
}

bool Scene::addLight(const char * path)
{
	return false;
}

bool Scene::delLight(Light * light)
{
	return false;
}

bool Scene::delLight(const char * path)
{
	return false;
}

bool Scene::addModel(Model * model)
{
	return false;
}

bool Scene::addModel(const char * path)
{
	return false;
}

bool Scene::delModel(Model * model)
{
	return false;
}

bool Scene::delModel(const char * path)
{
	return false;
}

bool Scene::addShader(Shader * shader)
{
	return false;
}

bool Scene::addShader(char * fsPath, char * vsPath)
{
	Shader sh;

//		if (sh.addFS(fsPath) == true)
//			return(true);

//		if (sh.addVS(vsPath) == true)
//			return(true);

		shaders.push_back(sh);

	return false;
}

bool Scene::delShader(Shader * shader)
{
	return false;
}

bool Scene::delShader(char * fsPath, char * vsPath)
{
	return false;
}

bool Scene::addAmbLight(float x, float y, float z)
{
	return false;
}

bool Scene::addDirLight(float x, float y, float z)
{
	return false;
}

bool Scene::addSpotLight(float x, float y, float z)
{
	return false;
}

bool Scene::delAmbLight(float x, float y, float z)
{
	return false;
}

bool Scene::delDirLight(float x, float y, float z)
{
	return false;
}

bool Scene::delSpotLight(float x, float y, float z)
{
	return false;
}

void Scene::setSkyNegX(const char * path)
{
}

void Scene::setSkyNegY(const char * path)
{
}

void Scene::setSkyNegZ(const char * path)
{
}

void Scene::setSkyPosX(const char * path)
{
}

void Scene::setSkyPosY(const char * path)
{
}

void Scene::setSkyPosZ(const char * path)
{
}

void Scene::setWaterNegX(const char * path)
{
}

void Scene::setWaterNegY(const char * path)
{
}

void Scene::setWaterNegZ(const char * path)
{
}

void Scene::setWaterPosX(const char * path)
{
}

void Scene::setWaterPosY(const char * path)
{
}

void Scene::setWaterPosZ(const char * path)
{
}

void Scene::updCamera(void)
{
}

void Scene::updLights(void)
{
}

void Scene::updModels(void)
{
}

void Scene::updShaders(void)
{
}

void Scene::updWater(void)
{
}

void Scene::updSky(void)
{
}

void Scene::render(void)
{
}

void Scene::vsync(void)
{
}
