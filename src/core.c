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
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);   
}

void CloseWindow(void) {
    glfwDestroyWindow(window);
    glfwTerminate();
}

bool WindowShouldClose(void) {
    if (glfwWindowShouldClose(window)) {
        return true;
    }
    return false;
} 

void SetBackground(Color color) {
    glClearColor(color.r, color.g, color.b, color.a);
    glClear(GL_COLOR_BUFFER_BIT);        
}