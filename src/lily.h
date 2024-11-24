/**
 * @file lily.h
 * @brief Lily is a lightweight C UI library for sleek, cross-platform interfaces.
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
 * - InitializeWindow(int width, int height, const char* title)
 * - CloseWindow()
 * - WindowShouldClose() 
 * - BeginDraw()
 * - ClearBackground(Color color)
 */

#ifndef LILY_H
#define LILY_H

// --- Platform-specific Macros for Shared Library Visibility ---
#if defined(_WIN32) || defined(_WIN64)
   // Define LYAPI for Windows shared libraries (.dll)
   #if defined(BUILD_LIBTYPE_SHARED)
      #define LYAPI __declspec(dllimport)
   #else
      #define LYAPI __declspec(dllexport)
   #endif
#else
   // Shared library visibility for Unix-based systems
   #if defined(BUILD_LIBTYPE_SHARED)
      #define LYAPI __attribute__((visibility("default")))
   #endif
#endif

#ifndef LYAPI
   #define LYAPI
#endif

// Basic Colors
Color Red = { 230, 41, 55, 255 };

// --- Boolean Type Definition ---
#if !defined(__cplusplus) && !defined(bool)
    typedef enum bool { false = 0, true = !false } bool;
#endif

// --- Structure Definition ---
typedef struct Color {
   unsigned char r;  // Red Color (0-255)
   unsigned char g;  // Green Color (0-255)
   unsigned char b;  // Blue Color (0-255)
   unsigned char a;  // Alpha Color (0-255)
} Color;

// --- Function Declarations ---
#if defined(__cplusplus)
extern "C" {
#endif

// Window-related functions
LYAPI void InitializeWindow(int width, int height, const char* title);
LYAPI void ExitWindow(void);
LYAPI bool ShouldClose(void);

// Drawing functions
LYAPI void ApplyBackground(Color color);
LYAPI void BeginDraw(void);
LYAPI void EndDraw(void);

#if defined(__cplusplus)
}
#endif

#endif // LILY_H
