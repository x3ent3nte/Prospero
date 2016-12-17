

#ifndef ACTOR_HPP
#define ACTOR_HPP

#define GLM_FORCE_RADIANS
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include <cmath>

#define GLEW_STATIC
#include <GL/glew.h>

#include <GLFW/glfw3.h>
#include <random>

#include "MyMath.hpp"

class Actor
{
public:
    
    glm::vec3 pos;
    glm::vec3 waypoint;
    
    glm::vec3 colour;
    
    GLfloat speed;
    
    Actor();
    Actor(glm::vec3 posx);
    Actor(GLfloat x, GLfloat y, GLfloat z);
    
    virtual void process(GLfloat delta);
    
    virtual void move();
};


#endif 
