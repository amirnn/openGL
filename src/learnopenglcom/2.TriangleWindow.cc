#include "Triangle.h"
#include <stdlib.h>

int main(int argc, char const *argv[])
{   
    std::string vertexShaderCodePath="../src/shaders/triangleVertexShader.glsl";
    std::string framgentShaderCodePath="../src/shaders/triangleFramgmentShader.glsl";
    Triangle::Triangle app(vertexShaderCodePath,framgentShaderCodePath);
    try
    {
        app.run();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
