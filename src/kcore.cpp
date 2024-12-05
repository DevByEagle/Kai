#include <cstdlib>
#include <cstring>
#include "kargo.h"

namespace Kargo
{
    Path* LoadPath(const String &filename, const String &mode)
    {
        Path *path = (Path *)malloc(sizeof(Path));

        if (!path)
            return nullptr;

        path->filename = filename.c_str();
        path->stream = fopen(path->filename, mode.c_str());
        if (!path->stream)
        {
            free(path);
            return NULL;
        }

        return path;
    }
}