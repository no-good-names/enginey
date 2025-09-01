//
// Created by carp on 8/31/25.
//

#ifndef CONTEXT_H
#define CONTEXT_H
#include <glad/glad.h>
#include <GLFW/glfw3.h>

enum DRAW_MODE { WIREFRAME = 0, FILLED = 1 };

class Context {
public:
    Context(int width, int height);
    ~Context();
    int getWidth() const {return height;}
    int getHeight() const {return height;}
    GLFWwindow* getWindow() const { return window; }
    int closeWindow() const { return glfwWindowShouldClose(window); }
private:
    int width;
    int height;
    GLFWwindow *window;
};

void setDrawMode(DRAW_MODE mode);

#endif //CONTEXT_H
