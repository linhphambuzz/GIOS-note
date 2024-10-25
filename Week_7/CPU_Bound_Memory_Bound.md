
- How do we know if a thread is CPU bound or memory bound? We need to use historic information.
- When we looked previously at determining whether a process was more interactive or more CPU intensive, we looked at the amount of time the process spent sleeping.
-  This approach won't work in this case for two reasons.
	- First of all, the thread is not really sleeping when it is waiting on memory access. It is waiting at some stage in the processor pipeline, not on some software queue.
	- Second, to keep track of the sleep time we were using software methods and that is too slow at this level. The context switch takes on the order of cycles, so we need to be able to make our decision on what to run very quickly.
-> We need some hardware-level information in order to help make our decision.


![[Pasted image 20241008114039.png]]


## Hardware counter 

Most modern platforms contain **hardware counters** that get updated as the processor executes and keep information about various aspects of execution, like :
- Cached ussage 
- - L1, L2 … LLC cache misses
- Instructions Per Cycle (IPC) metrics
- Power/Energy usage data
### Software and Tools 
- To access the hardwarew counter 
- - oprofile
- Linux perf tool
### How does hardware counter help the scheduler make scheduling decision?
- Many practical scheduling techniques rely on the use of hardware counters to understand something about the resource needs of a thread.
- The scheduler can use this information to pick a good mix of the threads that are available in the runqueue to schedule in the system so that all of the components of the system are well utilized and the threads interfere with each other as little as possible.
- One counter can tell us different things about a thread 
- There isn't a unique way to interpret the info provided from the hardware counter -> we estimate what kind of resources a thread needs 
- Scheduler can make informed decisions: 
	-  Schedulers often look at multiple counters across the CPU and can rely on models that have built for a specific platform and that have been trained using some well-understood workloads.


- ![[Pasted image 20241008115518.png]]
--> These hardware counters can be useful for resources in general, not only for hardware scheduling. 