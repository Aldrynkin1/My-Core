#include <utility>

extern "C" {
    #include "../c_include/include/allocator.h"
}

#include <iostream>
#include <string>



template <typename T>
void destroy_object(Allocator* arena, T* ptr) {
    if (!ptr) return;
    
    ptr->~T(); 
    allocate_free(arena, ptr, sizeof(T)); 
}