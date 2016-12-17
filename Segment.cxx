
/*
#include "Segment.hpp"

Segment::Segment(Organism * leaderx, int links):Organism(leaderx->pos.x, leaderx->pos.y, leaderx->pos.z)
{
    leader = leaderx;
    if(links > 0)
    {
        follower =  new Segment(this, links-1);
        hasFollower = true;
    }
    else
    {
        hasFollower = false;
    }
}

void Segment::process(GLfloat speedx)
{
    speed = speedx;
    move();
    
    if(hasFollower)
    {
        follower->process(speed);
    }
}

void Segment::move()
{
    if(glm::length(leader->pos- pos) > 10.0f)
    {
        pos += glm::normalize((leader->pos) - pos) * speed;
    }
}

*/
