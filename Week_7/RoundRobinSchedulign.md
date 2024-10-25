- When it comes to running jobs with the same priority there are alternatives to FCFS and SJF. A popular option is **round robin scheduling**. Consider the following scenario.
- ![[Pasted image 20241006090721.png]]
- We have three tasks that all arrive at the same time and are all present in the runqueue.
- If T1 has to wait for I/O operation, T2 will then be executed. T1 will then be put on the back of the queue 
-  We first remove T1 from the queue and schedule it on the CPU. When T1 completes, T2 will be removed from the queue and scheduled on the CPU. When T2 completes, T3 will be removed from the queue and scheduled on the CPU. 
## Round Robin with Priority 
- include pre-emption
- task is scheduled FCFS\
- they don't have to run to completion 

## Round Robin with interleaving
![[Pasted image 20241006091424.png]]

-A further modification that makes sense with round robin is not to wait until the tasks explicitly yield, but instead to interrupt them in order to mix in all the tasks in the system at the same time. For example, we would give each task a window of one time unit before interrupting it to schedule a new task. We call this mechanism **timeslicing**.
