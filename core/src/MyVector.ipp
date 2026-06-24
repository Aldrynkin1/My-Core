#include "../include/MyVector.hpp"

namespace Core
{
    template <typename T>
    MyVector<T>::MyVector(Allocator *allocator, size_t initial_capacity)
        : m_allocator(allocator), m_size(0), m_capacity(initial_capacity)
    {
        if (m_capacity > 0 && m_allocator != nullptr)
        {
            void *raw_mem = allocate(m_allocator, nullptr, m_capacity * sizeof(T));
            data = reinterpret_cast<T *>(raw_mem);
        }
        else
        {
            data = nullptr;
        }
    }

    template <typename T>
    void MyVector<T>::reserve(size_t new_cap)
    {
        if (new_cap <= m_capacity)
        {
            return;
        }

        void *raw_mem = allocate(m_allocator, nullptr, new_cap * sizeof(T));
        T *new_data = reinterpret_cast<T *>(raw_mem);
        size_t constructed_count = 0;

        try
        {
            for (size_t i = 0; i < m_size; i++)
            {
                new (&new_data[i]) T(data[i]);
                constructed_count++;
            }
        }
        catch (...)
        {
            for (size_t i = 0; i < constructed_count; i++)
            {
                new_data[i].~T();
            }
            allocate_free(m_allocator, new_data, new_cap * sizeof(T));
            throw;
        }

        for (size_t i = 0; i < m_size; i++)
        {
            data[i].~T();
        }

        if (data != nullptr)
        {
            allocate_free(m_allocator, data, m_capacity * sizeof(T));
        }

        data = new_data;
        m_capacity = new_cap;
    }

    template <typename T>
    void MyVector<T>::push_back(const T &value)
    {
        if (m_size >= m_capacity)
        {
            reserve(m_capacity == 0 ? 1 : m_capacity * 2);
        }
        new (&data[m_size]) T(value);
        m_size++;
    }

}