#include "Triangle.h"


int main(int argc, char const *argv[]) {
  std::string vertexShaderCodePath = "../../src/shaders/2.vertexShader.glsl";
  std::string fragmentShaderCodePath = "../../src/shaders/2.fragmentShader.glsl";
  Triangle::Triangle app(vertexShaderCodePath, fragmentShaderCodePath, 2U,6U);
  app.vertices->data.clear();
  app.vertices->data = {
    // positions         // colors
     0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // bottom right
    -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // bottom left
     0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // top 
  };
  app.vertices->indices.clear();
  app.vertices->indices = {
      // note that we start from 0!
      0, 1, 2
  };
/*  app.runnable.push_back([&]() {
    double timeValue = glfwGetTime();
    double greenValue = (sin(timeValue) / 2.0) + 0.5;
    int vertexColorLocation =
        glGetUniformLocation(app.linkedShaderProgram, "cpuColor");
    glUniform4f(vertexColorLocation, 0.0f, (float)greenValue, 0.0f, 1.0f);
  });*/
  try {

    app.run();

  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
