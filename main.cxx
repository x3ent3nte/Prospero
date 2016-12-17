
#include "main.hpp"

void loadTexture(GLuint & tex, std::string path );
void createVertexBuffer();

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void keyAction(GLFWwindow* window);

GLuint WIDTH = 800, HEIGHT = 600;

GLfloat mixVal = 0.5f;

GLfloat deltaTime = 0.0f;
GLfloat lastFrame = 0.0f;

GLuint VBO;
GLuint VAO;
GLuint EBO;

Camera * cam;

Gaia * gaia;

bool keys[1024];

int main(int argc, const char * argv[])
{
    srand((int) time(NULL));
    
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    
    const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    glfwWindowHint(GLFW_RED_BITS, mode->redBits);
    glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
    glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
    glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);
    
    GLFWwindow * window = glfwCreateWindow(mode->width, mode->height, "Aleph One", glfwGetPrimaryMonitor(), NULL);
    glfwMakeContextCurrent(window);
    
    WIDTH = mode->width;
    HEIGHT = mode->height;
    
    glfwSetKeyCallback(window, key_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);
    
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    
    int screenWidth;
    int screenHeight;
    glfwGetFramebufferSize(window, &screenWidth, &screenHeight);
    
    glewExperimental = GL_TRUE;
    glewInit();
    glViewport(0, 0, screenWidth, screenHeight);
    
    glEnable(GL_DEPTH_TEST);
    
    
    //player = * new Player(0.0f, 0.0f, 0.0f);
    cam = new Camera(0.0f, 0.0f, 800.0f, WIDTH, HEIGHT);
    //cam.attach(&player);
    
    Shader ourShader = * new Shader("/Users/Gabriel/Desktop/prospero/vertex.glsl", "/Users/Gabriel/Desktop/prospero/fragment.glsl");
    
    
    gaia = new Gaia();
    
    GLuint texture1;
    loadTexture(texture1, "/Users/Gabriel/Desktop/prospero/images/snow_1.jpg");
    
    GLuint texture2;
    loadTexture(texture2, "/Users/Gabriel/Desktop/prospero/images/blue_white.jpg");

    createVertexBuffer();
    
    ourShader.Use();
    
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture1);
    glUniform1i(glGetUniformLocation(ourShader.Program, "ourTex1"), 0);
    
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, texture2);
    glUniform1i(glGetUniformLocation(ourShader.Program, "ourTex2"), 1);
    
    while(!glfwWindowShouldClose(window))
    {
        GLfloat currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        
        glfwPollEvents();
        keyAction(window);
        
        gaia->process(deltaTime);
        //player.process(deltaTime);
        cam->process(deltaTime);
        
        //glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
        
        glClearColor(0.1f, 0.0f, 0.14f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        glUniform1f(glGetUniformLocation(ourShader.Program, "mixValue"), mixVal);
        
        glm::mat4 eye;
        eye = cam->calcLookMatrix();

        glm::mat4 projection;
        projection = cam->calcProjMatrix();
        
        GLint modelLoc = glGetUniformLocation(ourShader.Program, "model");
        GLint eyeLoc = glGetUniformLocation(ourShader.Program, "eye");
        GLint projLoc = glGetUniformLocation(ourShader.Program, "projection");
        GLint colourLoc = glGetUniformLocation(ourShader.Program, "colourX");
        
        glUniformMatrix4fv(eyeLoc, 1, GL_FALSE, glm::value_ptr(eye));
        glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
        
        glBindVertexArray(VAO);
        /*
        glm::mat4 model;
        model = glm::translate(model, player.pos);
        
        model = glm::rotate(model, player.pitch, player.right);
        model = glm::rotate(model, -player.yaw, glm::vec3(0.0f, 0.1f, 0.0f));

        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        
        glDrawArrays(GL_TRIANGLES, 0, 36);
        */
        
        for (GLuint i = 0; i < gaia->orgs.size(); i++)
        {
            Organism org = * gaia->orgs[i];
            glBindVertexArray(VAO);
            /*glUniform1f(glGetUniformLocation(ourShader.Program, "red"), org.colour.x);
            glUniform1f(glGetUniformLocation(ourShader.Program, "green"), org.colour.y);
            glUniform1f(glGetUniformLocation(ourShader.Program, "blue"), org.colour.z);*/
            
            glm::mat4 model;
            model = glm::translate(model, org.pos);
            //model = glm::rotate(model, (GLfloat)glfwGetTime() * 50.0f, glm::vec3(0.5f, 0.5f, 0.0f));
            glUniform3f(colourLoc, org.colour.x, org.colour.y, org.colour.z);
            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
            
            glDrawArrays(GL_TRIANGLES, 0, 36);
            
            while(org.follower != nullptr)
            {
                org = * org.follower;
                glUniform3f(colourLoc, org.colour.x, org.colour.y, org.colour.z);
                //glBindVertexArray(VAO);
                glm::mat4 model;
                model = glm::translate(model, org.pos);
                //model = glm::rotate(model, (GLfloat)glfwGetTime() * 50.0f, glm::vec3(0.5f, 0.5f, 0.0f));
                glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
                
                glDrawArrays(GL_TRIANGLES, 0, 36);
                
            }
        }
        glBindVertexArray(0);
        
        glfwSwapBuffers(window);
    }
    
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    
    glfwTerminate();
    
    return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    if(action == GLFW_PRESS)
    {
        keys[key] = true;
    }
    else if(action == GLFW_RELEASE)
    {
        keys[key] = false;
    }
}

void keyAction(GLFWwindow* window)
{
    if(keys[GLFW_KEY_W])
    {
        cam->moveForward();
    }
    if(keys[GLFW_KEY_S])
    {
        cam->moveBack();
    }
    if(keys[GLFW_KEY_A])
    {
        cam->moveLeft();
    }
    if(keys[GLFW_KEY_D])
    {
        cam->moveRight();
    }
    if(keys[GLFW_KEY_Q])
    {
        cam->moveUp();
    }
    if(keys[GLFW_KEY_E])
    {
        cam->moveDown();
    }
    
    if(keys[GLFW_KEY_I])
    {
        cam->pitchUp();
    }
    if(keys[GLFW_KEY_K])
    {
        cam->pitchDown();
    }
    if(keys[GLFW_KEY_J])
    {
        cam->yawLeft();
    }
    if(keys[GLFW_KEY_L])
    {
        cam->yawRight();
    }
    if(keys[GLFW_KEY_U])
    {
        cam->rollLeft();
    }
    if(keys[GLFW_KEY_O])
    {
        cam->rollRight();
    }

    if(keys[GLFW_KEY_ESCAPE])
    {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
    if (keys[GLFW_KEY_UP])
    {
        if(mixVal < 1.0f)
        {
            mixVal += 0.05f;
        }
        
    }
    if (keys[GLFW_KEY_DOWN])
    {
        if(mixVal > 0.1f)
        {
            mixVal -= 0.05f;
        }
    }

}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    cam->mouseMove(xpos, ypos);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    cam->mouseZoom(xoffset, yoffset);
}

void loadTexture(GLuint & tex, std::string path)
{
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    int image_width, image_height;
    unsigned char* image = SOIL_load_image(path.c_str(), &image_width, &image_height, 0, SOIL_LOAD_RGB);
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image_width, image_height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);
    
    SOIL_free_image_data(image);
    glBindTexture(GL_TEXTURE_2D, 0);
}

void createVertexBuffer()
{
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    //glGenBuffers(1, &EBO);
    
    glBindVertexArray(VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(shapes::cube), shapes::cube, GL_STATIC_DRAW);
    
    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    //glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat),(GLvoid*)0);
    glEnableVertexAttribArray(0);
    
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3* sizeof(GLfloat)));
    glEnableVertexAttribArray(1);
    
    glVertexAttribPointer(2, 2, GL_FLOAT,GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
    glEnableVertexAttribArray(2);
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    glBindVertexArray(0);
}
































