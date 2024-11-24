#include "src/core.c"
#include <stdio.h>

int main(void) {
    int Width = 800;
    int Height = 600;
    Color color = {0, 150, 255, 255};

    InitializeWindow(Width, Height, "Test Window");
    
    while (!WindowShouldClose()) {
        // Render here (if needed)
        SetBackground(color);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    CloseWindow();
}