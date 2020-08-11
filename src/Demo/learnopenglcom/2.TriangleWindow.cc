#include "Triangle.h"
#include <stdlib.h>

int main(int argc, char const *argv[])
{   
    std::string vertexShaderCodePath="../../src/shaders/0.vertexShader.glsl";
    std::string framgentShaderCodePath="../../src/shaders/0.framgmentShader.glsl";
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
