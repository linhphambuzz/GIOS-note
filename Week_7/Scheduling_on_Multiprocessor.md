
## Shared memory processor 

![[Pasted image 20241007205841.png]]

- Multiple CPUs 
- Each have their own caches (i.e: l1, l2 )
- Last level cache may or may not be used by the CPU
- Finally, there is system memory (DRAM) which is shared across the CPUs.

## Multicores 

- Multicores present in CPU 
- Each core has it's own private L1/L2 cache, 
- and the CPU as a whole shares an LLC. 
- DRAM is present in this system as well.

--> As far as the operating system is concerned, it sees all of the CPUs and all of the cores in the CPUs as entities onto which it can schedule tasks.

## Scheduling 


- Since the performance of processes/threads is highly dependent on the amount of execution state that is present in the CPU cache - as opposed to main memory - it makes sense that we would want to schedule tasks on to CPUs such that we can maximize how "hot" we can keep our CPU caches. To achieve this, we want to schedule our tasks back on the same CPUs they had been executing on in the past. This is known as **cache affinity**.
### Cache Affinity 

- To achieve cache affinity, we can have a hierarchical scheduling architecture
- which maintains a load balancing component that is responsible for dividing the tasks among CPUs. Each CPU then has its own scheduler with its own runqueue, and is responsible for scheduling tasks on that CPU exclusively.
- To load balance across the CPUs, we can look at the length of each of the runqueues to ensure one is not too much longer than the other. In addition, we can detect when a CPU is idle, and rebalance some of the work from the other queues on to the queue associated with the idle CPU.
![[Pasted image 20241007212051.png]]
- In addition to having multiple processors, it is possible to have multiple memory nodes. 
- The CPUs and the memory nodes will be connected via some physical interconnect.
- Memory nodes can connect to some subset of the CPUs.
- In most configurations it is common that a memory node will be closer to a socket of multiple processors,, which means that access to this memory node from those processors is faster than accessing some remote memory node.
- We call these platforms **non-uniform memory access** (NUMA) platforms.
- ![[Pasted image 20241007212747.png]]
- From a scheduling perspective, what makes sense is to keep tasks on the CPU closest to the memory node where their state is, in order to maximize the speed of memory access. We refer to this as **NUMA-aware scheduling**.

