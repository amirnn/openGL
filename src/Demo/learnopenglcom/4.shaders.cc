#include "Triangle.h"
#include <GL/glew.h>
#include <cmath>
#include <iostream>

int main(int argc, char const *argv[]) {
  std::string vertexShaderCodePath = "../../src/shaders/1.vertexShader.glsl";
  std::string framgentShaderCodePath = "../../src/shaders/1.fragmentShader.glsl";
  Triangle::Triangle app(vertexShaderCodePath, framgentShaderCodePath);
  app.verticies.data.clear();
  app.verticies.data = {
      0.5,  0.5,  0.0, // top right
      0.5,  -0.5, 0.0, // bottom right
      -0.5, -0.5, 0.0, // bottom left
      -0.5, 0.5,  0.0  // top left
  };
  app.verticies.indices = {
      // note that we start from 0!
      0, 1, 3, // first triangle
      1, 2, 3  // second triangle
  };
  app.runable.push_back([&]() {
    double timeValue = glfwGetTime();
    double greenValue = (sin(timeValue) / 2.0) + 0.5;
    int vertexColorLocation =
        glGetUniformLocation(app.linkedShaderProgram, "cpuColor");
  });
  try {

    app.run();

  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
