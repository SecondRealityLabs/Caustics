#pragma once

class Camera
{

	private:

		float ox, oy, oz;
		float dx, dy, dz;
		float tx, ty, tz;

		float fov;

	public:
	
		Camera();
		~Camera();

		void init(void);
		void shut(void);

		void setPosition(float x, float y, float z);
		void setLookAt(float x, float y, float z);
		void setFOV(float fov);

};

