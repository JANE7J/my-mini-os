# Mini OS Simulation

A C-based project that simulates basic components of an Operating System such as:
- Task Scheduling
- Memory Management
- Process Control Block (PCB)

## Features

- Priority-based Task Scheduler
- Simple Memory Allocation and Free
- Process state transitions (NEW → READY → RUNNING → TERMINATED)

## How to Run

```bash
gcc -o build/os main.c scheduler/scheduler.c memory.c process.c -Iinclude
./build/os
