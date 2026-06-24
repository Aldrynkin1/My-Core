#include "../include/allocator.h"
#include <stdlib.h>

static uintptr_t align_forward(uintptr_t ptr, size_t alignment)
{
    return (ptr + (alignment - 1)) & ~(alignment - 1);
}

void allocator_init(Allocator *alloc, size_t size)
{
    alloc->total_size = size;
    alloc->start_ptr = (char *)malloc(size);
    alloc->current_pointer = alloc->start_ptr;
    alloc->alignment = 8;
    alloc->free_list = NULL;
}

void allocator_destroy(Allocator *alloc)
{
    free(alloc->start_ptr);
    alloc->start_ptr = NULL;
    alloc->current_pointer = NULL;
    alloc->free_list = NULL;
}

void *allocate(Allocator *alloc, void *ptr, size_t size)
{
    if (size != 0)
    {
        if (size < sizeof(FreeBlock))
        {
            size = sizeof(FreeBlock);
        }
    }

    FreeBlock *prev = NULL;
    FreeBlock *curr = alloc->free_list;

    while (curr != NULL)
    {
        if (curr->size >= size)
        {
            void *reused_ptr = (void *)curr;
            if (prev == NULL)
            {
                alloc->free_list = curr->next;
            }
            else
            {
                prev->next = curr->next;
            }

            return reused_ptr;
        }
        prev = curr;
        curr = curr->next;
    }
    uintptr_t current_addr = (uintptr_t)alloc->current_pointer;
    uintptr_t aligned_addr = align_forward(current_addr, alloc->alignment);

    size_t used_bytes = (char *)aligned_addr - alloc->start_ptr;

    if (used_bytes + size > alloc->total_size)
    {
        return NULL;
    }
    alloc->current_pointer = (char *)(aligned_addr + size);

    return (void *)aligned_addr;
}

void allocate_free(Allocator *alloc, void *ptr, size_t size)
{
    if (ptr == NULL || size == 0) return;

    if (size < sizeof(FreeBlock))
    {
        size = sizeof(FreeBlock);
    }

    char *char_ptr = (char *)ptr;

    if (char_ptr + size == alloc->current_pointer)
    {
        alloc->current_pointer = char_ptr;
        return;
    }
    FreeBlock *new_block = (FreeBlock *)ptr;
    new_block->size = size;

    new_block->next = alloc->free_list;
    alloc->free_list = new_block;
}

void allocate_reset(Allocator *alloc)
{
    alloc->current_pointer = alloc->start_ptr;
    alloc->free_list = NULL;
}

size_t get_free_memory(Allocator *alloc)
{
    return alloc->total_size - get_used_memory(alloc);
}

size_t get_used_memory(Allocator* alloc) {
    return alloc->current_pointer - alloc->start_ptr;
}