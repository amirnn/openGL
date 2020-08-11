//Vertex Shader
#version 450 core
layout (location = 0) in vec3 position;
void main(){
    gl_Position = vec4(vec3(position),1.0f);
}