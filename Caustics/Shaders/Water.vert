      
	  //uniform sampler2D water2;
      varying vec3 position;

      void main() 
	  {
       
	    //vec4 info = texture2D(water2, gl_Vertex.xy * 0.5 + 0.5);
        //position = gl_Vertex.xzy;
        //position.y += info.r;
        gl_Position = gl_ModelViewProjectionMatrix * vec4(position, 1.0);

	  }