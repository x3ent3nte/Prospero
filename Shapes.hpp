

#ifndef SHAPES_HPP
#define SHAPES_HPP


namespace shapes
{
    GLfloat size = 3.2f;

    GLfloat cube[]  =
    {
        -size, -size, -size,    0.5f, 0.0f, 1.0f,   0.0f, 0.0f,
        size, -size, -size,     0.5f, 0.0f, 1.0f,   1.0f, 0.0f,
        size,  size, -size,     0.0f, 0.0f, 1.0f,   1.0f, 1.0f,
        size,  size, -size,     0.0f, 0.0f, 1.0f,   1.0f, 1.0f,
        -size,  size, -size,    0.5f, 0.0f, 1.0f,   0.0f, 1.0f,
        -size, -size, -size,    0.5f, 0.0f, 1.0f,   0.0f, 0.0f,
        
        -size, -size,  size,  0.5f, 0.0f, 1.0f,     0.0f, 0.0f,
        size, -size,  size,  0.5f, 0.0f, 1.0f,      1.0f, 0.0f,
        size,  size,  size,  0.0f, 0.0f, 1.0f,      1.0f, 1.0f,
        size,  size,  size,  0.0f, 0.0f, 1.0f,      1.0f, 1.0f,
        -size,  size,  size,  0.5f, 0.0f, 1.0f,     0.0f, 1.0f,
        -size, -size,  size,  0.5f, 0.0f, 1.0f,     0.0f, 0.0f,
        
        -size,  size,  size,  0.5f, 0.0f, 1.0f,     1.0f, 0.0f,
        -size,  size, -size,  0.5f, 0.0f, 1.0f,     1.0f, 1.0f,
        -size, -size, -size,  0.0f, 0.0f, 1.0f,     0.0f, 1.0f,
        -size, -size, -size,  0.0f, 0.0f, 1.0f,     0.0f, 1.0f,
        -size, -size,  size,  0.5f, 0.0f, 1.0f,     0.0f, 0.0f,
        -size,  size,  size,  0.5f, 0.0f, 1.0f,     1.0f, 0.0f,
        
        size,  size,  size,  0.5f, 0.0f, 1.0f,      1.0f, 0.0f,
        size,  size, -size,  0.5f, 0.0f, 1.0f,      1.0f, 1.0f,
        size, -size, -size,  0.0f, 0.0f, 1.0f,      0.0f, 1.0f,
        size, -size, -size,  0.0f, 0.0f, 1.0f,      0.0f, 1.0f,
        size, -size,  size,  0.5f, 0.0f, 1.0f,      0.0f, 0.0f,
        size,  size,  size,  0.5f, 0.0f, 1.0f,      1.0f, 0.0f,
        
        -size, -size, -size,  0.5f, 0.0f, 1.0f,     0.0f, 1.0f,
        size, -size, -size,  0.5f, 0.0f, 1.0f,      1.0f, 1.0f,
        size, -size,  size,  0.0f, 0.0f, 1.0f,      1.0f, 0.0f,
        size, -size,  size,  0.0f, 0.0f, 1.0f,      1.0f, 0.0f,
        -size, -size,  size,  0.5f, 0.0f, 1.0f,     0.0f, 0.0f,
        -size, -size, -size,  0.5f, 0.0f, 1.0f,     0.0f, 1.0f,
        
        -size,  size, -size,  0.5f, 0.0f, 1.0f,     0.0f, 1.0f,
        size,  size, -size,  0.5f, 0.0f, 1.0f,      1.0f, 1.0f,
        size,  size,  size,  0.0f, 0.0f, 1.0f,      1.0f, 0.0f,
        size,  size,  size,  0.0f, 0.0f, 1.0f,      1.0f, 0.0f,
        -size,  size,  size,  0.5f, 0.0f, 1.0f,     0.0f, 0.0f,
        -size,  size, -size,  0.5f, 0.0f, 1.0f,     0.0f, 1.0f,
    };

}
#endif
