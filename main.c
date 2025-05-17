#include <stdio.h>
#include "include/task.h"
#include "scheduler/scheduler.h"
#include "memory.h"
#include "process.h"

int main() {
    // ----- Task Scheduler part -----
    printf("=== Task Scheduler ===\n");
    Task tasks[] = {
        {1, 1, 4, 2},
        {2, 3, 5, 1},
        {3, 0, 6, 3},
        {4, 5, 7, 2}
    };

    int n = sizeof(tasks) / sizeof(Task);
    schedule_tasks(tasks, n);

    // ----- Memory Manager part -----
    printf("\n=== Memory Manager Test ===\n");
    memory_init();
    memory_print();

    int a = memory_allocate(100);
    printf("Allocated block at %d\n", a);
    memory_print();

    int b = memory_allocate(200);
    printf("Allocated block at %d\n", b);
    memory_print();

    memory_free(a);
    printf("Freed block at %d\n", a);
    memory_print();

    // ----- PCB (Process Control Block) part -----
    printf("\n=== PCB Management Test ===\n");

    PCB p1 = {1, NEW, 2, 0};
    PCB p2 = {2, NEW, 1, 0};

    print_process(&p1);
    print_process(&p2);

    change_state(&p1, READY);
    change_state(&p2, READY);

    print_process(&p1);
    print_process(&p2);

    run_process(&p1);
    print_process(&p1);

    change_state(&p1, TERMINATED);
    print_process(&p1);

    return 0;
}
