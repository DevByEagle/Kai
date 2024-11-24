# Lily 🚀

<!-- ![Project Logo](https://via.placeholder.com/200x100) -->  

Lily is a lightweight C UI library for sleek, cross-platform interfaces.


<!--## ✨ Features

- [x] ****-->

## 🛠 Requirements

- **[GLFW]** `v3.4+`
- **[OpenGL]** `Any Version`


## 🚀 Installation

### Option 1: Using Git and Building from Source

1. Clone the repository:
   ```bash
   git clone https://github.com/DevByEagle/Lily.git
   ```

2. Navigate to the project directory:
   ```bash
   cd Lily
   ```
3. Build the library:
   ```bash
   mkdir build
   cd build
   cmake ..
   ```
### Option 2: Using Prebuilt Binaries
Alternatively, you can download prebuilt binaries for your platform:

1. Go to the [Releases page](https://github.com/DevByEagle/Lily/releases).
2. Download the appropriate prebuilt binary for your platform.
3. Extract the binary and link the library to your project.

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