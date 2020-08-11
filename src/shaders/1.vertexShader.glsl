#version 450 core
layout (location = 0) in vec3 inputs;
void main(){
    gl_Position = vec4(inputs,1.0);
}