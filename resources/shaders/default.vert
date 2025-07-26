#version 430 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord;

uniform vec3 uPosition;
uniform float uScale;

out vec4 oColor;
out vec2 oTexCoord;

void main()
{
   gl_Position = vec4((aPos.x + uPosition.x) * uScale, (aPos.y + uPosition.y) * uScale, (aPos.z + uPosition.z) * uScale, 1.0);
   oColor = vec4(aColor, 1.0f);
   oTexCoord = aTexCoord;
}
