
#ifndef ORGANISM_HPP
#define ORGANISM_HPP

#include <iostream>

#define GLM_FORCE_RADIANS
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include <cmath>

#define GLEW_STATIC
#include <GL/glew.h>

#include <GLFW/glfw3.h>
#include <random>

#include "Gaia.hpp"
#include "Actor.hpp"

class Gaia;

class Organism
{
public:
    
    glm::vec3 pos;
    glm::vec3 waypoint;
    
    glm::vec3 colour;
    glm::vec3 base_colour;
    
    GLfloat speed;

    Gaia * gaia;
    
    GLfloat age;
    bool isAlive;
    
    bool isMale;
    
    bool isPregnant;
    int baby_timer;

    int sense_timer;
    
    Organism * leader;
    Organism * follower;
    
    Organism * target;
    
    GLfloat charge;
    bool electric;
    
    Organism(glm::vec3 posx, Organism * leaderx, int segs, Gaia * gaiax);
    ~Organism();
    
    void process(GLfloat);
    void move();

    void sense();
    
    void reproduce();
    Organism * findPartner();
    
    void becomePregnant();
    void giveBirth();
    
    void signalColour(GLfloat charge);
};

#endif
