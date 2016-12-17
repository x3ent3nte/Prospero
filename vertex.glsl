#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 colour;
layout (location = 2) in vec2 tex;

out vec3 colourV;
out vec2 texV1;
out vec2 texV2;

uniform mat4 model;
uniform mat4 eye;
uniform mat4 projection;

void main()
{
    gl_Position = projection * eye * model * vec4(position, 1.0f);
    texV1 = vec2(tex.x, 1.0f - tex.y);
    texV2 = tex;
    colourV = colour;
}
