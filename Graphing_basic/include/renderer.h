#ifndef RENDERER_H
#define RENDERER_H

#include <stddef.h>

#include <glad/glad.h>
// include order: glad -> glfw3
#include <GLFW/glfw3.h>

typedef struct {
  GLuint shader_program;
  GLuint VAO;
  GLuint VBO;
  size_t vertex_count;
} ShaderSystem;

GLint check_shader(GLuint shader);

GLint check_program(GLuint program);

GLFWwindow *init_GL_and_create_window(void);

ShaderSystem load_shaders(void);

void render_frame(ShaderSystem *shader_system);

#endif
