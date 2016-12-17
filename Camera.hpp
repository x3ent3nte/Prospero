
#ifndef CAMERA_HPP
#define CAMERA_HPP

#define GLM_FORCE_RADIANS
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "glm/gtc/quaternion.hpp"
#include "glm/gtx/quaternion.hpp"

#include <cmath>

#define GLEW_STATIC
#include <GL/glew.h>

#include <GLFW/glfw3.h>

#include "Player.hpp"

class Camera
{
    
private:
    glm::vec3 pos;
    
    glm::vec3 forward = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
    glm::vec3 right = glm::vec3(1.0f, 0.0f, 0.0f);
    
    GLfloat width;
    GLfloat height;
    
    GLfloat yaw = 270.0f;
    GLfloat pitch =  0.0f;
    GLfloat roll = 0.0f;
    
    GLfloat lastX;
    GLfloat lastY;
    
    GLfloat fov;
    
    GLfloat speed;
    
    bool firstMouse = true;
    
    Player * player;
    bool isAttached = false;
    
public:
    
    Camera(GLfloat x, GLfloat y, GLfloat z, GLfloat widthx, GLfloat heightx);
    
    glm::mat4 calcLookMatrix();
    
    glm::mat4 calcProjMatrix();
    
    void process(GLfloat delta);
    
    void mouseMove(double xpos, double ypos);
    
    void mouseZoom(double xoffset, double yoffset);
    
    void moveToAttached();
    
    void moveForward();
    
    void moveBack();
    
    void moveRight();
    
    void moveLeft();
    
    void moveUp();
    
    void moveDown();
    
    void pitchUp();
    
    void pitchDown();
    
    void yawRight();
    
    void yawLeft();
    
    void rollRight();
    
    void rollLeft();
    
    void attach(Player * player);
    
private:
    void updateVectors();
};

#endif
