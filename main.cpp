#include <iostream>

#include "src/kargo.h"
#include "src/kcore.cpp"

int main(void) {
    Kargo::String message = "Hello, World!";
    Kargo::Path* path = Kargo::LoadPath("example.txt", "w");
}