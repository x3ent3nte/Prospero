
#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <cmath>
#include <random>

#include <thread>
#include <unistd.h>

#define GLEW_STATIC
#include <GL/glew.h>

#include <GLFW/glfw3.h>

#include "soil/SOIL.h"

#define GLM_FORCE_RADIANS
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtc/quaternion.hpp"
#include "glm/gtx/quaternion.hpp"

#include "Shader.hpp"
#include "Camera.hpp"
#include "Actor.hpp"
#include "Organism.hpp"
#include "Brain.hpp"
#include "Player.hpp"
#include "Shapes.hpp"
#include "Gaia.hpp"

#endif
