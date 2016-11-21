  const float IOR_AIR = 1.0;
  const float IOR_WATER = 1.333;
  const vec3 abovewaterColor = vec3(0.25, 1.0, 1.25);
  const vec3 underwaterColor = vec3(0.4, 0.9, 1.0);
  const float poolHeight = 1.0;
  uniform vec3 light;
  uniform vec3 sphereCenter;
  uniform float sphereRadius;
  uniform sampler2D tiles;
  uniform sampler2D causticTex;
  uniform sampler2D water;
  
  /* Ray - Cube intersection */
  vec2 intersectCube(vec3 origin, vec3 ray, vec3 cubeMin, vec3 cubeMax) 
  {

		vec3 tMin = (cubeMin - origin) / ray;
		vec3 tMax = (cubeMax - origin) / ray;
		vec3 t1 = min(tMin, tMax);
		vec3 t2 = max(tMin, tMax);
		float tNear = max(max(t1.x, t1.y), t1.z);
		float tFar = min(min(t2.x, t2.y), t2.z);

    return vec2(tNear, tFar);
  
  }
  
  /* Ray - Sphere intersection */	
  float intersectSphere(vec3 origin, vec3 ray, vec3 sphereCenter, float sphereRadius) 
  {

		vec3 toSphere = origin - sphereCenter;
		float a = dot(ray, ray);
		float b = 2.0 * dot(toSphere, ray);
		float c = dot(toSphere, toSphere) - sphereRadius * sphereRadius;
		float discriminant = b*b - 4.0*a*c;

	    if (discriminant > 0.0) 
		{
    
			float t = (-b - sqrt(discriminant)) / (2.0 * a);
			if (t > 0.0) return t;
		}
   
    return 1.0e6;
  
  }
  
  /* Ray-Triangle intersection */
  /*
  vec4 intersectTriangle(vec3 origin, vec3 ray, vec3 v0, vec3 v1, vec3 v2)
  {

	vec4 ret;

		// Find edges
		vec3 v0v1 = v1 - v0;
		vec3 v0v2 = v2 - v0;




		// Find determinant
		vec3 pvec = dir.crossProduct(v0v2);
		float det = v0v1.dotProduct(pvec);

		#ifdef CULLING
			// if the determinant is negative the triangle is backfacing
			// if the determinant is close to 0, the ray misses the triangle
		if (det < kEpsilon) return vec4(0, 0, 0, false);
		#else

		// ray and triangle are parallel if det is close to 0
		if (fabs(det) < kEpsilon) return vec4(0, 0, 0, false);
		#endif
		
		float invDet = 1 / det;

		vec3 tvec = orig - v0;
		u = tvec.dotProduct(pvec) * invDet;
		
		if (u < 0 || u > 1) return vec4(0, 0, 0, false);

		vec3 qvec = tvec.crossProduct(v0v1);

		v = dir.dotProduct(qvec) * invDet;
		if (v < 0 || u + v > 1) return vec4(0, 0, 0, false);
    
		t = v0v2.dotProduct(qvec) * invDet;
    
		// Find vector
		ret.u = u;	
		ret.v = v;
		ret.t = t;

    return vec4(u, v, t, true);

  }*/
