![[Pasted image 20240930194643.png]]
- The scheduler selects one of the tasks in the ready queue and then schedules it on the CPU. Tasks may become ready a number of different ways.
- Whenever the CPU becomes idle, we need to run the scheduler. For example, if a task makes an I/O request and is placed on the wait queue for that device, the scheduler has to select a new task from the ready queue to run on the CPU.
- When a timeslice expires, the scheduler must be run.

## start the prog.
- Once the scheduler selects a task to be scheduled, that task is dispatched onto the CPU. The operating system context switches to the new task, enters user mode, sets the program counter, and execution begins.
- How do we decide which task to be selected? This depends on the scheduling policy/algorithm. How does the scheduler accomplish its job? This depends very much on the structure of ready queue, also known as a **runqueue**. The decision of the runqueue and the scheduling algorithm are tightly coupled: a data structure that is optimized for one algorithm may be a poor choice for implementing another.