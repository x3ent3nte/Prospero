/*
#ifndef SEGMENT_HPP
#define SEGMENT_HPP

#define GLM_FORCE_RADIANS

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include <iostream>
#include <cmath>

#define GLEW_STATIC
#include <GL/glew.h>

#include <GLFW/glfw3.h>
#include <random>

#include "Organism.hpp"

class Segment: public Organism
{
public:
    
    Segment(Organism * leaderx, int links);
    
    void process(GLfloat delta);
    
    void move();
};
 
#endif
*/
