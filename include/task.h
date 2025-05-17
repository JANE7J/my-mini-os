#ifndef TASK_H
#define TASK_H

typedef struct {
    int id;
    int start_time;
    int end_time;
    int priority; // Lower number = higher priority
} Task;

void print_task(Task t);

#endif
