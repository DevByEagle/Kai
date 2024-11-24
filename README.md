# Lily 🚀

<!-- ![Project Logo](https://via.placeholder.com/200x100) -->  

Lily is a lightweight C UI library for sleek, cross-platform interfaces.


<!--## ✨ Features

- [x] ****-->

## 🛠 Requirements

- **[GLFW]** `v3.4+`
- **[OpenGL]** `Any Version`


## 🚀 Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/DevByEagle/Lily.git
   ```
2. Navigate to the project directory:
   ```bash
   cd Lily
   ```
3. Building the libaray:
   ```bash
   mkdir build
   cd build
   cmake ..
   ```

## 💡 Example
Here’s how you can use **Lily**:

```c
#include "lily.h"

int main(void) {
    InitializeWindow(800, 600, "Test Window");
    
    while (!ShouldClose()) {
        BeginDraw();
            ApplyBackground(Red);
        EndDraw();
    }

    ExitWindow();
}
```

## 👥 Community and Support

Join the **Lily** community:

<!-- - **Website**: Visit -->
- **Twitter:** Follow [@DevByEagle](https://x.com/DevByEagle).