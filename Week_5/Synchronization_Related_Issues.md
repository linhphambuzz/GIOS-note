
## Synchronization-related Issues 

![[Pasted image 20240920151158.png]]
- T1 holds the mutex and is executing on one CPU. T2 and T3 are blocked. T4 is executing on another CPU and wishes to lock the mutex.
- The normal behavior would be to place T4 on the queue associated with the mutex. However, on a multiprocessor system where things can happen in parallel, it may be the case that by the time T4 is placed on the queue, T1 has released the mutex
- If the critical section is very short, the more efficient case for T4 is not to block, **but just to spin** (trying to acquire the mutex in a loop).
- If the critical section is long, it makes **more sense to block** (that is, be placed on a queue and retrieved at some later point in time). This is because it takes CPU cycles to spin, and we don't want to burn through cycles for a long time. 
- Mutexes which sometimes block and sometimes spin are called **adaptive mutexes.** These only make sense on multiprocessor systems, since we only want to spin if the owner of the mutex is currently executing in parallel to us.
### Owner of mutexes 
- We need to store some information about the owner of a given mutex at a given time, so we can determine if the owner is currently running on a CPU, which means we should potentially spin. Also, we need to keep some information about the length of the critical section, which will give us further insight into whether we should spin or block.


## Destroying threads 
![[Pasted image 20240920151445.png]]

 - Once a thread is no longer needed, the memory associated with it should be freed. However, thread creation takes time, so it makes sense to reuse the data structures instead of freeing and creating new ones.

- When a thread exits, the data structures are not immediately freed. Instead, the thread is marked as being on **death row**.
- Periodically, a special **reaper** thread will perform garbage collection on these thread data structures. 
- If a request for a thread comes in before a thread on death row is reaped, the thread structure can be reused, which results in some performance gains.



In the linux kernel's code base, a minimum of how many threads are needed to allow a system to boot? 20 

What is the name of the variables used to set this limit? max_threads