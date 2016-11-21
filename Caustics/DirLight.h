#pragma once

#include "Light.h"

class DirLight :
	public Light
{

	private:

		float ox, oy, oz;
		float dx, dy, dz;

		float r, g, b;

	public:
	
		DirLight();
		~DirLight();

		void getOrigin(float* x, float* y, float* z);
		void getDirection(float* x, float* y, float* z);
		void getColor(float* r, float* g, float* b);

		void setOrigin(float& x, float& y, float& z);
		void setDirection(float& x, float& y, float& z);
		void setColor(float& r, float& g, float& b);

};

