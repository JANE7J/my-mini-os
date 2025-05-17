#include <stdio.h>
#include "process.h"

void print_process(PCB *p) {
    const char *state_str[] = {"NEW", "READY", "RUNNING", "WAITING", "TERMINATED"};
    printf("PID: %d, State: %s, Priority: %d, PC: %d\n",
           p->pid, state_str[p->state], p->priority, p->program_counter);
}

void change_state(PCB *p, ProcessState new_state) {
    p->state = new_state;
}

void run_process(PCB *p) {
    p->state = RUNNING;
    printf("Running process %d\n", p->pid);
    p->program_counter++;  // Simulate executing an instruction
}
