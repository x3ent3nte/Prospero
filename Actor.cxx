

#include "Actor.hpp"

Actor::Actor()
{
    pos = mymath::randomPoint(10.0f);
    waypoint += mymath::randomPoint(1200.0f);
}

Actor::Actor(glm::vec3 posx)
{
    pos = posx;
    waypoint += mymath::randomPoint(1200.0f);
}

Actor::Actor(GLfloat x, GLfloat y, GLfloat z)
{
    pos = glm::vec3(x,y,z);
    waypoint += mymath::randomPoint(2.0f);
}

void Actor::process(GLfloat delta)
{
    speed = 10.0f * delta;
    move();
}

void Actor::move()
{
    if(glm::length(waypoint - pos) < speed)
    {
        pos = waypoint;
        waypoint += mymath::randomPoint(100.0f);
        return;
    }
    pos += glm::normalize((waypoint - pos)) * speed;
}














