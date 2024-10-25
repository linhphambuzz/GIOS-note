When T2 arrives, it is the only task in the system, so the scheduler will schedule it. When T1 and T3 arrive, T2 should be preempted, in line with our SJF policy. The execution of the rest of the scenario is as follows.
![[Pasted image 20240930204810.png]]
- Whenever tasks enter the runqueue, the scheduler needs to be invoked so that it can invoke the new task's runtime, and make a decision as to whether it should preempt the currently executing task.
## Execution time ?

- We are still holding our assumption that we know the execution time of the task. In reality, this is not really a fair assumption, as the execution time depends on many different things that may be out of our perception. We can generate heuristics about running time based on execution times that have been recorded for similar jobs in the past. We can think about how long a task took to run the very last time or the average execution time over the past n times (a **windowed average**).

