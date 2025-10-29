#version 450
layout(location = 0) in vec2 fragUV;
layout(location = 1) in vec3 fragColor;

layout(location = 0) out vec4 outColor;

layout(binding = 1) uniform sampler2D texSampler; // optional

void main() {
    // If you have a texture, sample it:
    // vec4 t = texture(texSampler, fragUV);
    // outColor = t;
    // Otherwise color by vertex color:
    outColor = vec4(fragColor, 1.0);
}