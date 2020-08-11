#include "Triangle.h"
#include <cmath>


int main(int argc, char const *argv[]) {
  std::string vertexShaderCodePath = "../../src/shaders/2.vertexShader.glsl";
  std::string framgentShaderCodePath = "../../src/shaders/2.fragmentShader.glsl";
  Triangle::Triangle app(vertexShaderCodePath, framgentShaderCodePath, 6U);
  app.verticies->data.clear();
  app.verticies->data = {
    // positions         // colors
     0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // bottom right
    -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // bottom left
     0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // top 
  };
  app.verticies->indices = {
      // note that we start from 0!
      0, 1, 2
  };
  app.runable.push_back([&]() {
    double timeValue = glfwGetTime();
    double greenValue = (sin(timeValue) / 2.0) + 0.5;
    int vertexColorLocation =
        glGetUniformLocation(app.linkedShaderProgram, "cpuColor");
    glUniform4f(vertexColorLocation, 0.0f, (float)greenValue, 0.0f, 1.0f);
  });
  try {

    app.run();

  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
