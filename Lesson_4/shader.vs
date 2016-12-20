#version 330  // 告诉编译器我们的目标GLSL编译器版本是3.3

layout (location = 0) in vec3 Position;  

void main() {
    gl_Position = vec4(0.5 * Position.x, 0.5 * Position.y, Position.z,1.0);
}