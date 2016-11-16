// Caustics.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <conio.h>

#include "OpenGL.h"
#include "Scene.h"

int main(int argC, char* argV[])
{
	// vars
	Camera *cam1, *cam2, *cam3;
	OpenGL *openGL;
	Scene  *scene;
	
		// make
		cam1 = new(Camera);
		cam2 = new(Camera);
		cam3 = new(Camera);
		openGL = new(OpenGL);
		scene = new(Scene);		
		
		// init
		cam1->init();
		cam2->init();
		cam3->init();
		openGL->init();
		scene->init();

		// camera
		cam1->setLookAt(0.0, 0.0, 0.0);
		cam1->setPosition(0.0, 0.0, 0.0);
		scene->addCamera(cam1);

		cam2->setLookAt(0.0, 0.0, 0.0);
		cam2->setPosition(0.0, 0.0, 0.0);
		scene->addCamera(cam2);
		
		cam3->setLookAt(0.0, 0.0, 0.0);
		cam3->setPosition(0.0, 0.0, 0.0);
		scene->addCamera(cam3);
		
		// lights
		scene->addAmbLight(0.0, 0.0, 0.0);
		scene->addDirLight(0.0, 0.0, 0.0);
		scene->addSpotLight(0.0, 0.0, 0.0);
		
		// models
		scene->addModel("submarine");

		// sky cubemap
		scene->setSkyNegX("skyNegX.png");
		scene->setSkyNegY("skyNegY.png");
		scene->setSkyNegZ("skyNegZ.png");
		scene->setSkyPosX("skyPosX.png");
		scene->setSkyPosY("skyPosY.png");
		scene->setSkyPosZ("skyPosZ.png"); 

		// water cubemap
		scene->setWaterNegX("waterNegX.png");
		scene->setWaterNegY("waterNegY.png");
		scene->setWaterNegZ("waterNegZ.png");
		scene->setWaterPosX("waterPosX.png");
		scene->setWaterPosY("waterPosY.png");
		scene->setWaterPosZ("waterPosZ.png");

		// shaders
		scene->addShader("ambient.fs", "ambient.vs");
		scene->addShader("caustic.fs", "caustic.vs");
		scene->addShader("cubemap.fs", "cubemap.vs");
		scene->addShader("fresnel.fs", "fresnel.vs");
		scene->addShader("reflect.fs", "reflect.vs");
		scene->addShader("refract.fs", "refract.vs");
		scene->addShader("shadow.fs", "shadow.vs");
		scene->addShader("water.fs", "water.vs");

		// loop
		while (!_kbhit())
		{

			// update camera
			scene->updCamera();

			// update light
			scene->updLights();

			// update models
			scene->updModels();

			// update sky
			scene->updSky();

			// update water
			scene->updWater();

			// render frame
			scene->render();

			// v-sync
			scene->vsync();

		}

		// shut
		cam1->shut();
		cam2->shut();
		cam3->shut();
		openGL->shut();
		scene->shut();
		
		// delete
		delete(cam1);
		delete(cam2);
		delete(cam3);
		delete(openGL);
		delete(scene);

	// exit	
	return 0;
}