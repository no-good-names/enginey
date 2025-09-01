//
// Created by carp on 8/31/25.
//

#include "context.h"

#include <cstdio>
#include <cstdlib>

Context::Context(const int width, const int height) {
    this->width=width;
    this->height=height;
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    this->window = glfwCreateWindow(this->width, this->height, "Demo", NULL, NULL);
    if (this->window == NULL) {
        fprintf(stderr, "glfw window creation failed\n");
        glfwTerminate();
        exit(-1);
    }
    glfwMakeContextCurrent(this->window);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        fprintf(stderr, "Failed GLAD init");
        exit(-1);
    }

    glViewport(0, 0, this->width=width, this->height=height);
}

Context::~Context() {
    glfwDestroyWindow(this->window);
    glfwTerminate();
}

void setDrawMode(const DRAW_MODE mode) {
    switch (mode) {
        case WIREFRAME:
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            break;
        case FILLED:
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            break;
        default:
            break;
    }
}

