#include "iostream"

extern "C" {
    #include "../c_include/include/allocator.h"
}

void test_allocate_memory() {
    Allocator my_alloc;

    int* a = reinterpret_cast<int *>(allocate(&my_alloc, nullptr, sizeof(int)));
    int b = 10;

    std::cout << &a << std::endl;
}