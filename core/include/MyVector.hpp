#pragma once
#include <utility>
#define MY_VECTOR_HPP_INCLUDED
extern "C"
{
#include "../c_include/include/allocator.h"
}

#include <iostream>
#include <string>

namespace Core
{
    class Logger;
    template <typename T>
    class MyVector
    {
    private:
        T *data = nullptr;
        size_t m_size = 0;
        size_t m_capacity = 0;
        Allocator *m_allocator = nullptr;

    public:
        T &operator[](size_t index) { return data[index]; }
        const T &operator[](size_t index) const { return data[index]; }

        MyVector(Allocator *allocator) : m_allocator(allocator) {}
        MyVector(Allocator *allocator, size_t initial_capacity);

        ~MyVector()
        {
            for (size_t i = 0; i < m_size; i++)
            {
                data[i].~T();
            }
            if (data != nullptr && m_allocator != nullptr)
            {
                allocate_free(m_allocator, data, m_capacity * sizeof(T));
            }
        }

        MyVector(const MyVector &) = delete;
        MyVector &operator=(const MyVector &) = delete;

        void push_back(const T &value);
        void reserve(size_t new_cap);

        size_t size() const { return m_size; }
        size_t capacity() const { return m_capacity; }

        static void PrintVector(const MyVector &vector)
        {
            for (size_t i = 0; i < vector.m_size; i++)
            {
                std::cout << vector[i] << " ";
            }
            std::cout << std::endl;
        }
    };
}

#include "../src/MyVector.ipp"
