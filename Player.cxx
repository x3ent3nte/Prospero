

#include "Player.hpp"

Player::Player(GLfloat x, GLfloat y, GLfloat z)
{
    pos = glm::vec3(x, y, z);
    thrust = 200.f;
}

void Player::process(GLfloat delta)
{
    speed = thrust * delta;
    updateVectors();
    cameraPoint = pos - (forward * 30.0f);
    cameraPoint += glm::vec3(0.0f, 15.0f, 0.0f);
    //cameraPoint = pos + (forward * 170.0f);
    moveForward();
}

void Player::moveForward()
{
    pos += forward * speed;
}

void Player::thrustIncrease()
{
    thrust += 4.0f;
    if(thrust > 2000.0f)
    {
        thrust = 2000.0f;
    }
}

void Player::thrustDecrease()
{
    thrust -= 4.0f;
    if(thrust < 120.0f)
    {
        thrust = 120.0f;
    }
}

void Player::pitchUp()
{
    pitch += turnSpeed;
    if (pitch > 89.0f)
    {
        pitch = 89.0f;
    }
}

void Player::pitchDown()
{
    pitch -= turnSpeed;
    if (pitch < -89.0f)
    {
        pitch = -89.0f;
    }
}

void Player::yawRight()
{
    yaw += turnSpeed;
}

void Player::yawLeft()
{
    yaw -= turnSpeed;
}

void Player::updateVectors()
{
    glm::vec3 front;
    front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    front.y = sin(glm::radians(pitch));
    front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    
    forward = glm::normalize(front);
    right = glm::normalize(glm::cross(forward, up));
}

