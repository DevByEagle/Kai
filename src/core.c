#include <stdio.h>
#include <stdlib.h>
#include <GLFW/glfw3.h>
#include "lily.h"

static GLFWwindow *window = NULL;

void InitializeWindow(int width, int height, const char *title)
{
    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        exit(EXIT_FAILURE);
    }

    window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!window) {
        fprintf(stderr, "Failed to create GLFW window\n");
        EndWindow();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
}

void ExitWindow(void) {
    glfwDestroyWindow(window);
    glfwTerminate();
}

bool ShouldClose(void) {
    if (glfwWindowShouldClose(window)) {
        return true;
    }
    return false;
} 

void BeginDraw(void) {
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void ApplyBackground(Color color) {
    glClearColor(color.r, color.g, color.b, color.a);        
}

void EndDraw(void) {
    glClear(GL_COLOR_BUFFER_BIT);
}