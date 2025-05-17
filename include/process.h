#ifndef PROCESS_H
#define PROCESS_H

typedef enum {
    NEW,
    READY,
    RUNNING,
    WAITING,
    TERMINATED
} ProcessState;

typedef struct {
    int pid;
    ProcessState state;
    int priority;
    int program_counter;  // Simulated instruction pointer
} PCB;

// Function declarations
void print_process(PCB *p);
void change_state(PCB *p, ProcessState new_state);
void run_process(PCB *p);

#endif
