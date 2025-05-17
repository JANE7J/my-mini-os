#include <stdio.h>
#include "memory.h"

static MemoryBlock memory[MEMORY_SIZE];  // Simulated memory blocks
static int block_count = 1;

void memory_init() {
    memory[0].start = 0;
    memory[0].size = MEMORY_SIZE;
    memory[0].free = true;
}

int memory_allocate(int size) {
    for (int i = 0; i < block_count; i++) {
        if (memory[i].free && memory[i].size >= size) {
            int alloc_start = memory[i].start;

            if (memory[i].size > size) {
                // Split block
                for (int j = block_count; j > i; j--) {
                    memory[j] = memory[j - 1];
                }
                block_count++;

                memory[i + 1].start = memory[i].start + size;
                memory[i + 1].size = memory[i].size - size;
                memory[i + 1].free = true;

                memory[i].size = size;
            }

            memory[i].free = false;
            return alloc_start;
        }
    }
    return -1; // No suitable block found
}

void memory_free(int start) {
    for (int i = 0; i < block_count; i++) {
        if (memory[i].start == start) {
            memory[i].free = true;

            // Merge adjacent free blocks
            if (i + 1 < block_count && memory[i + 1].free) {
                memory[i].size += memory[i + 1].size;
                for (int j = i + 1; j < block_count - 1; j++) {
                    memory[j] = memory[j + 1];
                }
                block_count--;
            }
            if (i > 0 && memory[i - 1].free) {
                memory[i - 1].size += memory[i].size;
                for (int j = i; j < block_count - 1; j++) {
                    memory[j] = memory[j + 1];
                }
                block_count--;
            }
            return;
        }
    }
}

void memory_print() {
    printf("Memory Blocks:\n");
    for (int i = 0; i < block_count; i++) {
        printf("Start: %d, Size: %d, %s\n", memory[i].start, memory[i].size,
               memory[i].free ? "Free" : "Used");
    }
}
