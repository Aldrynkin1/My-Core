#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct FreeBlock
{
    size_t size;
    struct FreeBlock *next;
} FreeBlock;

typedef struct {
    char *start_ptr;
    char *current_pointer;
    size_t total_size;
    size_t alignment;
    FreeBlock* free_list;
} Allocator;

void allocator_init(Allocator* alloc, size_t size);
void allocator_destroy(Allocator* alloc);
void *allocate(Allocator* alloc, void* ptr, size_t size);
void allocate_free(Allocator* alloc, void *ptr, size_t size);
void allocate_reset(Allocator* alloc);
size_t get_used_memory(Allocator* alloc);
size_t get_free_memory(Allocator* alloc);

#ifdef __cplusplus
}
#endif

#endif