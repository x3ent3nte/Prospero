
#include "Brain.hpp"


/*
Brain::Brain():Organism()
{
    follower = new Segment(this, 9);
    hasFollower = true;
}

Brain::Brain(Organism * parent): Organism(parent->pos.x, parent->pos.y, parent->pos.z)
{
    follower = new Segment(this, 4);
    hasFollower = true;

}

void Brain::process(GLfloat delta)
{
    speed = 110.0f * delta;
    
    move();
    
    if(hasFollower)
    {
        follower->process(speed);
    }
}

void Brain::move()
{
    if(glm::length(waypoint - pos) < speed)
    {
        pos = waypoint;
        waypoint += mymath::randomPoint(1000.0f);
        return;
    }
    pos += glm::normalize((waypoint - pos)) * speed;
}


*/











