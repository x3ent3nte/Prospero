

#include "Organism.hpp"

Organism::Organism(glm::vec3 posx, Organism * leaderx, int segs, Gaia * gaiax)
{
    pos = posx;
    waypoint = mymath::randomPoint(900.0f);

    leader = leaderx;

    target = nullptr;

    speed = 5.0f;

    gaia = gaiax;
    age = 0;
    isAlive = true;
    
    isPregnant = false;
    baby_timer = 0;

    sense_timer = (int)fmod(rand(), 15.0f);
    
    if(leader == nullptr)
    {
        if(fmod(rand(), 100.0f) > 50.0f)
        {
            isMale = true;
            base_colour = glm::vec3(0.4f, 0.0f, 0.5f);
        }
        else
        {
            isMale = false;
            base_colour = glm::vec3(0.6f, 0.0f, 0.8f);
        }
    }
    else
    {
        isMale = leader->isMale;
        if(isMale)
        {
            base_colour = glm::vec3(0.4f, 0.0f, 0.5f);
        }
        else
        {
            base_colour = glm::vec3(0.6f, 0.0f, 0.8f);
        }
    }

    colour = base_colour;
    
    if(segs > 0)
    {
        follower = new Organism(pos, this, segs-1, gaia);
    }
    else
    {
        follower = nullptr;
    }
    
    electric = false;
    charge = 0;
}

Organism::~Organism()
{
    if(follower != nullptr)
    {
        delete follower;
    }
}

void Organism::process(GLfloat delta)
{
    if(age > 4000.0f)
    {
        isAlive = false;
    }
    age += 1.0f;
    
    if(leader == nullptr && follower != nullptr)
    {
        //follower->signalColour((1.0f+(sin(glm::radians(50 * (GLfloat)glfwGetTime()))))/2);
        follower->signalColour(4.0f * delta);
    }

    if(isMale)
    {
        speed = 170.0f * delta;
    }
    else
    {
        speed = 110.0f * delta;
    }
    
    if(leader == nullptr)
    {
        sense_timer++;
        if(sense_timer == 80)
        {
            sense();
            sense_timer = 0;
        }
        reproduce();
    }
    move();
    
    if(follower != nullptr)
    {
        follower->process(delta);
    }
}

void Organism::move()
{
    if(leader == nullptr)
    {
        if(glm::length(waypoint - pos) < speed)
        {
            pos = waypoint;
            waypoint += mymath::randomPoint(500.0f);
            return;
        }
        pos += glm::normalize((waypoint - pos)) * speed;
    }
    else
    {
        if(glm::length(leader->pos- pos) > 8.0f)
        {
            pos += glm::normalize((leader->pos) - pos) * speed;
        }
    }
}

void Organism::sense()
{
    if(isMale)
    {
        target = findPartner();
    }
}

void Organism::reproduce()
{
    if(isMale)
    {
        if(target == nullptr)
        {
            return;
        }
        if(target->isPregnant)
        {
            target = nullptr;
            waypoint = pos + mymath::randomPoint(500.0f);
            return;
        }
        waypoint = target->pos;
        if(glm::length(waypoint - pos) < 5.0f)
        {
            target->becomePregnant();
            target = nullptr;
        }
    }
    else
    {
        if(isPregnant)
        {
            baby_timer++;
            
            if(baby_timer == 1500)
            {
                giveBirth();
                baby_timer = 0;
            }
        }
    }
}

void Organism::giveBirth()
{
    gaia->orgs.push_back(new Organism(pos, nullptr, 10, gaia));
    isPregnant = false;
}

Organism * Organism::findPartner()
{
    Organism * closest = nullptr;
    GLfloat closest_dist = FLT_MAX;
    
    for(int i=0; i<gaia->orgs.size(); i++)
    {
        Organism * org = gaia->orgs[i];
        if((!org->isMale) && (!org->isPregnant))
        {
            GLfloat dist = glm::length(org->pos - pos);
            if( dist < closest_dist )
            {
                closest = org;
                closest_dist = dist;
            }
        }
    }
    return closest;
}

void Organism::becomePregnant()
{
    if(isMale)
    {
        std::cout << "Major Error! \n";
    }
    
    isPregnant = true;
    
}

void Organism::signalColour(GLfloat current)
{
    if(!electric)
    {
        charge += current;
        if(follower != nullptr)
        {
            follower->signalColour(0.0f);
        }
        if(charge >= 2.0f)
        {
            colour = glm::vec3(0.3f, 0.9f, 0.9f);
            electric = true;
        }
    }
    else
    {
        if(follower != nullptr)
        {
            follower->signalColour(1.0f);
        }
        charge -= 1.0f;
        if(charge <= 0)
        {
            colour = base_colour;
            electric = false;
        }
    }
}























