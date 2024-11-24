#include <GL/gl.h>
#include "lily.h"

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#endif

void StartWindow(const char *title, int width, int height)
{
#if defined(_WIN32) || defined(_WIN64)
    HINSTANCE hInstance = GetModuleHandle(NULL);

    // Register a minimal window class
    WNDCLASS wc = {0};
    wc.style = CS_OWNDC; // Use a unique device context
    wc.lpfnWndProc = DefWindowProc; // Default window procedure
    wc.hInstance = hInstance;
    wc.lpszClassName = "SimpleOpenGLWindow";

    if (!RegisterClass(&wc)) {
        MessageBox(NULL, "Failed to register window class", "Error", MB_OK);
        return;
    }

    // Create the window
    HWND hwnd = CreateWindow(
        wc.lpszClassName, title,
        WS_OVERLAPPEDWINDOW | WS_VISIBLE,
        CW_USEDEFAULT, CW_USEDEFAULT, width, height,
        NULL, NULL, hInstance, NULL
    );

    if (!hwnd) {
        MessageBox(NULL, "Failed to create window", "Error", MB_OK);
        return;
    }

    // Setup OpenGL context
    HDC hdc = GetDC(hwnd);
    PIXELFORMATDESCRIPTOR pfd = {
        sizeof(PIXELFORMATDESCRIPTOR), 1,
        PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
        PFD_TYPE_RGBA, 32,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        24, 8, 0,
        PFD_MAIN_PLANE,
        0, 0, 0, 0
    };

    int pixelFormat = ChoosePixelFormat(hdc, &pfd);
    SetPixelFormat(hdc, pixelFormat, &pfd);
    HGLRC hglrc = wglCreateContext(hdc);
    wglMakeCurrent(hdc, hglrc);

    // OpenGL initialization
    glClearColor(0.1f, 0.2f, 0.3f, 1.0f); // Set clear color

    // Minimal rendering loop
    MSG msg = {0};
    while (msg.message != WM_QUIT) {
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        // Rendering
        glClear(GL_COLOR_BUFFER_BIT);
        SwapBuffers(hdc);
    }

    // Cleanup
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(hglrc);
    ReleaseDC(hwnd, hdc);
    DestroyWindow(hwnd);
#endif
}

bool IsWindowReady() {
    
}