#version 330                                                                        
                                                                                    
layout (location = 0) in vec3 uPosition;                                             
layout (location = 1) in vec2 uTexCoord;                                             
layout (location = 2) in vec3 uNormal;                                               
                                                                                    
uniform mat4 uWVP;                                                                  
uniform mat4 uWorld;                                                                
                                                                                    
out vec2 TexCoord0;                                                                 
out vec3 Normal0;                                                                   
out vec3 WorldPos0;                                                                 
                                                                                    
void main()                                                                         
{                          
                                                         
	gl_Position = uWVP * vec4(uPosition, 1.0);                                       
	TexCoord0   = uTexCoord;                                                         
	Normal0     = (uWorld * vec4(uNormal, 0.0)).xyz;                                 
	WorldPos0   = (uWorld * vec4(uPosition, 1.0)).xyz;                               

}
