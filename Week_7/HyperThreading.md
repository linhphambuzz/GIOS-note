
- The reason why we have to context switch among threads is because the CPU only has one set of registers to describe an execution context.
- Over time, hardware architects have realized they can hide some of the latency associated with context switching. 
- One of the ways that this has been achieved is to have CPUs with multiple sets of registers where each set of registers can describe the context of a separate thread.
- We call this **hyperthreading**. In hyperthreading, we have multiple hardware-supported execution context. We still have one CPU - so only one of these threads will execute at a given time - but context switching amongst the threads is very fast.
- This mechanism is referred to by many names:

	- hardware multithreading
	- hyperthreading
	- chip multithreading (CMT)
	- simultaneous multithreading (SMT)
- Modern platforms often support two hardware threads, though some high performance platforms may support up to eight. Modern systems allow for hyperthreading to be enabled/disabled at boot time, as there are tradeoffs to this approach.

- if hyperthreading is enabled, each of these hardware contexts appears to the scheduler as an entity upon which it can schedule tasks.
![[Pasted image 20241007213916.png]]

- SMT can also hide memory access latency 
- One of the decisions that the scheduler will have to make is which two threads to schedule on this hardware contexts. If the amount of time a thread is idling is greater than the amount of time to context switch twice, it makes sense to context switch