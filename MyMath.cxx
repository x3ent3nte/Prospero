

#include "MyMath.hpp"

namespace mymath
{
    GLfloat randomRange(GLfloat range)
    {
        return (fmod(rand(), range)) - (range/2);
    }

    glm::vec3 randomPoint(GLfloat range)
    {
    	GLfloat yaw = fmod(rand(), 359.0f);
    	GLfloat pitch = fmod(rand(), 359.0f) - 179.0f;

    	GLfloat x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
   		GLfloat y = sin(glm::radians(pitch));
    	GLfloat z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));

    	return  glm::vec3(x,y,z) * (GLfloat)fmod(rand(), range); 
        //return glm::vec3(randomRange(range), randomRange(range), randomRange(range));
    }
}
