#ifndef KARGO_H
#define KARGO_H

#include <cstdio>
#include "kstring.h"
#include "kstring.cpp"

namespace Kargo
{
    // Type Define
    struct Path {
        FILE* stream;       // Underlying file stream (or any other custom data type)
        const char* filename;     // Name of the file
    };
    // Function Define
    Path* LoadPath(const String& filename, const String& mode);
    // Class Define
}

#endif // KARGO_H
