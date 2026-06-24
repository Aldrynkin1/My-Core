#include "../include/MyVector.hpp"

void test_vector_create() {
    Allocator my_alloc;
    allocator_init(&my_alloc, 102400);

    Core::MyVector<int> vec(&my_alloc, 1024);

    for (int i = 0; i < 50; i++) {
        vec.push_back(i);
    }

    std::cout << "Capacity: " << vec.capacity() << std::endl; 
    std::cout << "Size: " << vec.size() << std::endl;

    for(int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }

    allocator_destroy(&my_alloc);
}
