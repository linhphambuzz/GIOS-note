
- To understand what is required from a scheduler in a hyperthreaded platform we first need to make some assumptions.
- First, we need to assume that a thread can issue an instruction on every CPU cycle. This means that a CPU bound thread will be able to maximize the **instructions per cycle** (IPC) metric.
- Second, we need to assume that memory access takes four cycles. What this means is that a memory bound thread will experience some idle cycles while it is waiting for the memory access to return.
- ![[Pasted image 20241007224403.png]]
- Third, we can also assume that hardware switching is instantaneous.

- Finally, we will assume that we have an SMT platform with two hardware threads.
## Co-Schedule compute-bound threads 

![[Pasted image 20241007224616.png]]
- Even though each thread is able to issue a CPU instruction during each cycle, only one thread will be able to issue an instruction at a time since there is only one CPU pipeline. As a result, these threads will interfere with one another as they compete for CPU pipeline resources.
- The best case scenario is that a thread idles every other cycle while it yields to the other thread issuing instructions. As a result, the performance of each thread degrades by a factor of two.
- In addition, the memory component is completely idle during this computation, as nothing is performing any memory access.

## Co- schedule Memory Bound threads 
![[Pasted image 20241007224926.png]]
Similar to the CPU-bound thread example, we still have idle time where both threads are waiting on memory access to return, which means wasted CPU cycles.

## Coschedule mixing compute-bound and memory-bound thread

![[Pasted image 20241007225346.png]]
- This solution seems best. We schedule the CPU-bound thread until the memory-bound thread needs to issue a memory request. We context switch over, issue the request, and then context switch back and continue our compute-heavy task. This way, we minimize the number of wasted CPU cycles.

- Scheduling a mix of memory/CPU intensive threads allows us to avoid or at least limit the contention on the processor pipeline and helps to ensure utilization across both the CPU and the memory components.

- Note that we will still experience some degradation due to the interference of these two threads, but it will be minimal relative to the co-scheduling of only memory- or CPU-bound threads.


