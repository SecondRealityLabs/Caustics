#pragma once

class Camera
{

	private:

		// origin
		float ox, oy, oz;

		// direction
		float dx, dy, dz;

		// target
		float tx, ty, tz;

		// fields-of-view
		float fov;

		// clip planes
		float zFar;
		float zNear;
	
		// frustum normals
		float negXnx, negXny, negXnz;
		float negYnx, negYny, negYnz;
		float negZnx, negZny, negZnz;

		float posXnx, posXny, posXnz;
		float posYnx, posYny, posYnz;
		float posZnx, posZny, posZnz;

		// frustum points
		float negXpx, negXpy, negXpz;
		float negYpx, negYpy, negYpz;
		float negZpx, negZpy, negZpz;
	
		float posXpx, posXpy, posXpz;
		float posYpx, posYpy, posYpz;
		float posZpx, posZpy, posZpz;

	public:
	
		Camera();
		~Camera();

		void init(void);
		void shut(void); 

		void getPosition(float* x, float* y, float* z);
		void getLookAt(float* x, float* y, float* z);
		void getFOV(float* fov);

		void setPosition(float& x, float& y, float& z);
		void setLookAt(float& x, float& y, float& z);
		void setFOV(float& fov);

		void getNegX(float* nx, float* ny, float* nz);
		void getNegY(float* nx, float* ny, float* nz);
		void getNegZ(float* nx, float* ny, float* nz);

		void getPosX(float* nx, float* ny, float* nz);
		void getPosY(float* nx, float* ny, float* nz);
		void getPosZ(float* nx, float* ny, float* nz);

		void setNegX(float& nx, float& ny, float& nz);
		void setNegY(float& nx, float& ny, float& nz);
		void setNegZ(float& nx, float& ny, float& nz);

		void setPosX(float& nx, float& ny, float& nz);
		void setPosY(float& nx, float& ny, float& nz);
		void setPosZ(float& nx, float& ny, float& nz);

};

