
#ifndef GAIA_HPP
#define GAIA_HPP

#include <stdio.h>
#include "Organism.hpp"
#include "MyMath.hpp"

class Organism;

class Gaia
{
public:
    
    std::vector <Organism *> orgs;
    
    Gaia();
    
    void process(GLfloat delta);
};

bool isDead(Organism * org);

#endif
