#include "src/core.c"
#include <stdio.h>

int main(void) {
    int Width = 800;
    int Height = 600;

    InitializeWindow(Width, Height, "Test Window");
    
    while (!ShouldClose()) {
        BeginDraw();
            ApplyBackground(Red);
        EndDraw();
    }

    ExitWindow();
}