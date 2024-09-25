For the CPU to start executing a process, the process must first be ready. At any given time, there may be many processes that are in the ready state, so the question becomes: how does the operating system decide which process to run next on the CPU?
[[Context_Switch]]
## CPU Scheduler

- The CPU scheduler manages how processes use the CPU resources.
- It determines which process will use the CPU next, and how long that process has to run.

### OS Roles 

1. **Pre-empt**: interrupt the current process and save its context
2. **Schedule**: select, the next process 
3. **Dispatch** : Once the process is chosen, the operating system must **dispatch** the process and switch into its context.

-> Since CPU resources are precious, the operating system needs to make sure that it spends the bulk of its time running processes, NOT making scheduling decisions.

### How often do we run the scheduler? 

- The more time we run the scheduler, the more time it takes away from using CPU for running processes. 
![[Pasted image 20240826174443.png]]
- , if the number of blocks of time spent scheduling equals the number of blocks spent executing, and the length of an execution block is the same as the length of a scheduling block, then the CPU _efficiency_ is only 50%!
- On the other hand, if the same number of blocks are spent scheduling as are spent executing, but the process runs for 10 times the length of the scheduling block, the efficiency increases to over 90%!

### Timeslice 
![[Pasted image 20240826174544.png]]

The amount of time that has been allocated to a process that is scheduled to run is known as a **timeslice**.

When designing a scheduler, we have to make important design decisions:

- What are appropriate timeslice values?
- What criteria is used to decide which process is the next to run?

