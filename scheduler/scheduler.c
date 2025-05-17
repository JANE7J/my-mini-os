#include <stdio.h>
#include <stdlib.h>
#include "scheduler.h"

void print_task(Task t) {
    printf("Task %d: Start=%d, End=%d, Priority=%d\n", t.id, t.start_time, t.end_time, t.priority);
}

int compare(const void *a, const void *b) {
    Task *t1 = (Task *)a;
    Task *t2 = (Task *)b;
    return t1->end_time - t2->end_time;
}

void schedule_tasks(Task tasks[], int n) {
    qsort(tasks, n, sizeof(Task), compare);

    printf("Scheduled Tasks:\n");
    int last_end = -1;
    for (int i = 0; i < n; i++) {
        if (tasks[i].start_time >= last_end) {
            print_task(tasks[i]);
            last_end = tasks[i].end_time;
        }
    }
}
