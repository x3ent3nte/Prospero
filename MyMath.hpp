

#ifndef MYMATH_HPP
#define MYMATH_HPP

#include <stdio.h>

#define GLM_FORCE_RADIANS
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"


#define GLEW_STATIC
#include <GL/glew.h>

#include <GLFW/glfw3.h>

namespace mymath
{

    GLfloat randomRange(GLfloat range);

    glm::vec3 randomPoint(GLfloat range);

}
#endif
