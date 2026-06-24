#include <iostream>
#include <string>
#include <utility>
#include "destroy.cpp"

extern "C" {
    #include "../c_include/include/allocator.h"
}

template <typename T, typename... Args>
T* create_object(Allocator* allocator, Args&&... args) {
    void* memory = allocate(allocator, nullptr, sizeof(T));
    if (!memory) return nullptr;

    return new (memory) T(std::forward<Args>(args)...);
}