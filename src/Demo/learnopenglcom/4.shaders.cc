#include "Triangle.h"
#include <cmath>


int main(int argc, char const *argv[]) {
  std::string vertexShaderCodePath = "../../src/shaders/1.vertexShader.glsl";
  std::string framgentShaderCodePath = "../../src/shaders/1.fragmentShader.glsl";
  Triangle::Triangle app(vertexShaderCodePath, framgentShaderCodePath);
  app.vertices->data.clear();
  app.vertices->data = {
      0.5,  0.5,  0.0, // top right
      0.5,  -0.5, 0.0, // bottom right
      -0.5, -0.5, 0.0, // bottom left
      -0.5, 0.5,  0.0  // top left
  };
  app.vertices->indices = {
      // note that we start from 0!
      0, 1, 2, // first triangle
      0, 2, 3  // second triangle
  };
  app.runnable.push_back([&]() {
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
