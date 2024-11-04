
## Objectives
- We can define latency as the time it takes a thread to acquire a free lock. Ideally, we want the thread to be able to acquire a free lock immediately with a single atomic instruction.
- In addition, we want the spinlock to have _low delay/waiting time_. We can define delay as the amount of time required for a thread to stop spinning and acquire a lock that has been freed. Again, we ideally would want the thread to be able to stop spinning and acquire a free lock immediately.
- Finally, we would like a design that _reduces contention_ on the shared bus or interconnect. By contention, we mean the contention due to the actual atomic memory references as well as the subsequent coherence traffic. Contention is bad because it will delay any other CPU that is trying to access memory. Most pertinent to our use case though, contention will also delay the acquisition and release of the spinlock.

![[Pasted image 20241102164708.png]]