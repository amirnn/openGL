#include "Triangle.h"

int main(int argc, char const *argv[])
{
    std::string vertexShaderCodePath="../../src/shaders/0.vertexShader.glsl";
    std::string framgentShaderCodePath="../../src/shaders/0.framgmentShader.glsl";
    Triangle::Triangle app(vertexShaderCodePath,framgentShaderCodePath);
    app.vertices->data.clear();
    app.vertices->data = {
        0.5, 0.5, 0.0,   // top right
        0.5, -0.5, 0.0,  // bottom right
        -0.5, -0.5, 0.0, // bottom left
        -0.5, 0.5, 0.0   // top left
    };
    app.vertices->indices = {
        // note that we start from 0!
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };
    try
    {
        app.run();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
