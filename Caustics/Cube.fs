    
    
    
    
    
    
    
    
    
    varying vec3 position;
    
    void main() 
    {
    
      gl_FragColor = vec4(getWallColor(position), 1.0);
    
      vec4 info = texture2D(water, position.xz * 0.5 + 0.5);
   
      if (position.y < info.r)
      {
        gl_FragColor.rgb *= underwaterColor * 1.2;
      }  

    }
    