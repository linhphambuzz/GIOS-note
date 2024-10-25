
## Timeslices 
- A **timeslice** (also known as a time quantum) is the maximum amount of uninterrupted time that can be given to a task.
- A task may run for a smaller amount of time than what the timeslice specifies. f the task needs to wait on an I/O operation, the task will be placed on a queue , or synchronize with another task, the task will execute for less than its timeslice before it is placed on the appropriate queue and preempted.
- Also, if a higher priority tasks becomes runnable before a lower priority task's timeslice has expired, the lower priority task will be preempted.
### In CPU sharing

- The use of timeslices allows for the tasks to be interleaved. That is, they will be timesharing the CPU. For I/O bound tasks, this is not super critical, as these tasks will often be placed on wait queues. However, for CPU bound tasks, timeslices are the only way that we can achieve timesharing.

## Example 
- Let's compare round robin scheduling with a timeslice of 1 to the FCFS and SJF algorithms across the metrics of throughput, average wait, and average completion.
- T1 runs for 1 sec, happens to be its exec time -> run to completion
- T2 is scheduled, after 1 sec, is pre-empted
- T3 is scheduled, run for 1 sec
- T2 is back on the run for the remianing of 9 sec 
1. Throughput: Task/sec remains the same 
2. Avg compoleteionm time 
![[Pasted image 20241006092351.png]]


## Benefit of time-slice method 
- short task is done sooner 
- more responsive 
- length IO ops inittiated soonner 

## Downside 

- Overheads: interrupt, schedule, ctx swicth
- keep ts >> context_siwtch_time

## Note
If we consider the overheads when we compute our metrics, we can see that our total time will increase slightly, so our throughput will go down. As well, each task will have to wait just a little longer to start, so our wait time and our completion time will increase.

As long as the timeslice is significantly longer than the amount of time it takes to context switch, we should be able to minimize the overheads of context switching.

in general we should consider the nature of the the task and the overhead of the system 

