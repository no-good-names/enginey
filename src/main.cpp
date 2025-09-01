#include "graphics/shader.h"
#include <cstdio>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "backend/context.h"
#include "graphics/model.h"

int SCR_WIDTH = 800;
int SCR_HEIGHT = 600;

void processInput(const Context& context);

float vertices[] = {
    -0.5f, 0.5f, 0.0f,
    0.5f, 0.5f, 0.0f,
    -0.5f, -0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
};

unsigned int indices[] = {
    0, 1, 2,
    2, 1, 3
};

int main() {
    const Context context(800, 600);
    const Shader shader("./res/shader.vsh", "./res/shader.fsh");
    const Model model(vertices, sizeof(vertices), indices, sizeof(indices));

    while(!context.closeWindow()) {
        // input
        processInput(context);

        // rendering
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shader.use();
        model.use();

        // events
        glfwSwapBuffers(context.getWindow());
        glfwPollEvents();
    }
    return 0;
}

void processInput(const Context& context) {
    if (glfwGetKey(context.getWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(context.getWindow(), true);
    if (glfwGetKey(context.getWindow(), GLFW_KEY_1) == GLFW_PRESS)
        setDrawMode(FILLED);
    if (glfwGetKey(context.getWindow(), GLFW_KEY_2) == GLFW_PRESS)
        setDrawMode(WIREFRAME);

}

