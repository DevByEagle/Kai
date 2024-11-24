/**
 * @file lily.h
 * @brief 
 *
 * @version 1.0.0
 * @date 2024-11-23
 *
 * @author DevByEagle
 *
 * @section LICENSE
 * The library is open-source and available under the MIT license.
 *
 * @section FUNCTIONS
 * - 
 */

#ifndef LILY_H
#define LILY_H

#if defined(_WIN32) || defined(_WIN64)
   // Define LYAPI for Windows shared libraries (.dll)
   #if defined(BUILD_LIBTYPE_SHARED)
      #define LYAPI __declspec(dllimport)
   #else
      #define LYAPI __declspec(dllexport)
   #endif
#else
   // Shared library visibility for Unix-based
   #if defined(BUILD_LIBTYPE_SHARED)
      #define LYAPI __attribute__((visibility("default")))
   #endif
#endif

#ifndef LYAPI
   #define LYAPI
#endif

// --- Structures Definition ---
#if !defined(__cplusplus) && !defined(bool)
    typedef enum bool { false = 0, true = !false } bool;
#endif

typedef struct Color {
   unsigned char r;
   unsigned char g;
   unsigned char b;
   unsigned char a;
} Color;

#if defined(__cplusplus)
extern "C" {
#endif

// Window-related functions
LYAPI void InitializeWindow(int width, int height, const char* title);
LYAPI void CloseWindow(void);
LYAPI bool WindowShouldClose(void);

//LYAPI void printx(const char* text, float x, float y);
LYAPI void SetBackground(Color color);

#if defined(__cplusplus)
}
#endif

#endif // UIX_H