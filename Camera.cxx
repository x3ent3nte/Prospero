

#include "Camera.hpp"

Camera::Camera(GLfloat x, GLfloat y, GLfloat z, GLfloat widthx, GLfloat heightx)
{
    pos = glm::vec3(x,y,z);
    
    fov = 75.0f;
    
    width = widthx;
    height = heightx;
    
    lastX =  width  / 2.0;
    lastY  =  height / 2.0;
    
    updateVectors();
}

void Camera::process(GLfloat delta)
{
    speed = 250.0f * delta;
    
    updateVectors();
    
    if(isAttached)
    {
        pitch = player->pitch;
        yaw = player->yaw;
        speed = player->speed;
        moveToAttached();
    }
}

void Camera::moveToAttached()
{
    pos = player->cameraPoint;
    /*if(glm::length(player->pos - pos) > 45.0f)
    {
        pos += glm::normalize(glm::vec3(player->pos.x, player->pos.y + 15.0f, player->pos.z) - pos) * speed;
    }*/
}

glm::mat4 Camera::calcLookMatrix()
{
    return glm::lookAt(pos, pos + forward, up);
}

glm::mat4 Camera::calcProjMatrix()
{
    return glm::perspective(glm::radians(fov), GLfloat(width) / GLfloat(height), 0.5f, 17000.0f);
}

void Camera::updateVectors()
{
    glm::vec3 front;
    front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    front.y = sin(glm::radians(pitch));
    front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    
    up = glm::vec3(0.0f, 1.0f, 0.0f);
    
    if((pitch <= -90.0f ) || (pitch >= 90.0f ))
    {
        up *= -1;
    }

    forward = glm::normalize(front);
    right = glm::normalize(glm::cross(forward, up));

    up = glm::normalize(glm::cross(forward, -right));
    
    up = glm::angleAxis(glm::radians(roll), forward) * up;
    right = glm::normalize(glm::cross(forward, up));
}

void Camera::attach(Player * playerx)
{
    player = playerx;
    isAttached = true;
}

void Camera::mouseMove(double xpos, double ypos)
{
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }
    
    GLfloat xoffset = xpos - lastX;
    GLfloat yoffset = lastY - ypos;
    lastX = xpos;
    lastY = ypos;
    
    GLfloat sensitivity = 0.07;
    xoffset *= sensitivity;
    yoffset *= sensitivity;
    
    if((pitch <= -90.0f ) || (pitch >= 90.0f ))
    {
        yaw -= xoffset;
    }
    else
    {
         yaw += xoffset;
    }
    pitch += yoffset;
    
    if(pitch > 180.0f)
    {
        pitch -= 360;
    }
    if(pitch < -180.0f)
    {
        pitch += 360;
    }
    
    updateVectors();
}

void Camera::mouseZoom(double xoffset, double yoffset)
{
    if (fov >= 15.0f && fov <= 90.0f)
    {
        fov += yoffset;
    }
    if (fov <= 15.0f)
    {
        fov = 15.0f;
    }
    if (fov >= 90.0f)
    {
        fov = 90.0f;
    }
}

void Camera::moveForward()
{
    pos += forward * speed;
}

void Camera::moveBack()
{
    pos -= forward * speed;
}

void Camera::moveRight()
{
    pos += right * speed;
}

void Camera::moveLeft()
{
    pos -= right * speed;
}

void Camera::moveUp()
{
    pos += up * speed;
}

void Camera::moveDown()
{
    pos -= up * speed;
}

void Camera::pitchUp()
{
    pitch += 2.0f;
    if(pitch > 180.0f)
    {
        pitch -= 360;
    }
}

void Camera::pitchDown()
{
    pitch -= 2.0f;
    if(pitch < -180.0f)
    {
        pitch += 360;
    }
}

void Camera::yawRight()
{
    if((pitch <= -90.0f ) || (pitch >= 90.0f ))
    {
        yaw -= 2.0f * cos(glm::radians(roll));
    }
    else
    {
        yaw += 2.0f * cos(glm::radians(roll));
    }
   
    if(yaw > 360)
    {
        yaw -= 360;
    }
    
    if(pitch > 180.0f)
    {
        pitch -= 360;
    }
    if(pitch < -180.0f)
    {
        pitch += 360;
    }
}

void Camera::yawLeft()
{
    if((pitch <= -90.0f ) || (pitch >= 90.0f ))
    {
        yaw += 2.0f * cos(glm::radians(roll));
    }
    else
    {
        yaw -= 2.0f * cos(glm::radians(roll));
    }
    
    if(yaw < 0)
    {
        yaw += 360;
    }
    
    
    if(pitch > 180.0f)
    {
        pitch -= 360;
    }
    if(pitch < -180.0f)
    {
        pitch += 360;
    }
}

void Camera::rollRight()
{
    roll += 2.0f;
    if(roll > 360)
    {
        roll -= 360;
    }
}

void Camera::rollLeft()
{
    roll -= 2.0f;
    if(roll < 0)
    {
        roll += 360;
    }
}


























