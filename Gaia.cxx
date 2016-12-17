
#include "Gaia.hpp"

Gaia::Gaia()
{   
    for(int i=0; i<1200; i++)
    {
        orgs.push_back(new Organism(mymath::randomPoint(10.0f), nullptr, 10, this));
    }
}

void Gaia::process(GLfloat delta)
{
    orgs.erase(std::remove_if(orgs.begin(), orgs.end(), isDead), orgs.end());
    
    for(int i = 0; i<orgs.size(); i++)
    {
        orgs[i]->process(delta);
    }
}

bool isDead(Organism * org)
{
    return !( org->isAlive);
}
