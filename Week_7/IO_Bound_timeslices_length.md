
## Scenario 
- 2 tasks: exec tiime =10 s
- Ctx switch= .1 s
- IO ops issued every 1 , competes in .5 s 
![[Pasted image 20241006111224.png]]
In both cases, regardless of the timeslice, each task is yielding the CPU after every second of operation - when it makes its I/O request. There isn't really any preemption going on. Thus the execution graphs and the metrics for timeslice values of 1 second and 5 seconds are identical.

## Scenario II 
only T2 is IO bound 
![[Pasted image 20241006111516.png]]

For I/O bound tasks, we want a smaller timeslice. We can keep throughput up and average wait time down with a smaller timeslice. As well, we can maximize device utilization with a smaller timeslice, as we can quickly switch between different tasks issuing I/O requests.
