

#ifndef PLAYER_HPP
#define PLAYER_HPP

#define GLM_FORCE_RADIANS

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include <cmath>

#define GLEW_STATIC
#include <GL/glew.h>

#include <GLFW/glfw3.h>
#include <random>

class Player
{
public:
    
    glm::vec3 pos;
    
    GLfloat speed;
    GLfloat thrust;
    
    glm::vec3 forward = glm::vec3(0.0f, 0.0f, -1.0f);;
    glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);;
    glm::vec3 right = glm::vec3(1.0f, 0.0f, 0.0f);;
    
    glm::vec3 cameraPoint;
    
    GLfloat yaw = -90.0f;
    GLfloat pitch =  0.0f;
    
    GLfloat turnSpeed = 1.0;
    
    Player(GLfloat x, GLfloat y, GLfloat z);
    
    void process(GLfloat delta);
    
    void moveForward();
    
    void thrustIncrease();
    void thrustDecrease();
    
    void pitchUp();
    void pitchDown();
    
    void yawRight();
    void yawLeft();
    
    void updateVectors();
};

#endif
