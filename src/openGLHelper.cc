#include "openGLHelper.h"

namespace OGLHelper {
void clearErrors() {
  while (glGetError() != GL_NO_ERROR);
}

bool getError() {
  while (GLenum error = glGetError()) {
    std::cout << "OpenGL error: " << error << std::endl;
    return false;
  }
  return true;
}
} // namespace OGLHelper