#version 450 core
layout(location = 0 ) in vec3 iPosition;
layout(location = 1 ) in vec3 iColor;
out vec3 vOColor; //vertex output color
void main(){
    gl_Position = vec4(iPosition, 1.0);
    vOColor = iColor;
}