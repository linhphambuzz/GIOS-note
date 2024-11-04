
## similar to mutexes 
- In some ways spinlocks are like mutexes. For example, a spinlock is used to provide mutual exclusion, and it has certain constructs that are similar to the mutex lock/unlock operations.
## differences than mutexes 

- When a spinlock is locked, and a thread is attempting to lock it, that thread is not blocked. Instead, the thread is spinning.
- It is running on the CPU and repeatedly checking to see if the lock has become free.
- With mutexes, the thread attempting to lock the mutex would have relinquished the CPU and allowed another thread to run. 
- With spinlocks, the thread will burn CPU cycles until the lock becomes free or until the thread becomes preempted for some reason.