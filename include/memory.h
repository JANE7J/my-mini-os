#ifndef MEMORY_H
#define MEMORY_H

#include <stdbool.h>

#define MEMORY_SIZE 1024  // Total memory size in units

typedef struct {
    int start;
    int size;
    bool free;
} MemoryBlock;

void memory_init();
int memory_allocate(int size);
void memory_free(int start);
void memory_print();

#endif
