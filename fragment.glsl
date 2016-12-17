#version 330 core

in vec3 colourV;
in vec2 texV1;
in vec2 texV2;

out vec4 colourF;

uniform float mixValue;

uniform sampler2D ourTex1;
uniform sampler2D ourTex2;

uniform vec3 colourX;

void main()
{
    //colourF = mix(texture(ourTex1, texV1), texture(ourTex2, texV1) , mixValue) * vec4(colourV, 1.0f);
    colourF = mix(texture(ourTex1, texV1), texture(ourTex2, texV1) , mixValue) * 2 * vec4((colourX + colourV)/2, 1.0f);
    //colourF = vec4(noise, 1.0f);
}
