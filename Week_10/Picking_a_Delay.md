## Static Delay 
- which is based on some fixed information, such as the CPU ID where the process is running.

- One benefit of this approach is its simplicity, and the fact that under high load static delays will likely spread out all of the atomic references such that there is little or no contention.
- The problem with this approach is that it will create unnecessary load under low contention. For example, if one process is running on a CPU with an ID of 1, and another process is running on a CPU with an ID of 32, and the delay calculation is 100ms * CPU ID, the second thread will have to wait an inordinate amount of time before executing, even though there is no contention.

## Dynamic Delay 

- To avoid the issue of excessive delays without contention, **dynamic delays** can be used. With dynamic delays, each thread will take a random delay value from a range of possible delays that increases with the "perceived" contention in the system.
- Under high load, both dynamic and static delays will be sufficient enough to reduce contention within the system.
_________________________
**How can we evaluate how much contention there is in the system?**
- A good metric to estimate the contention is to track the number of failed `test_and_set` operations.  The more these operations fail, the more likely it is that there is a higher degree of contention.
- If we delay after each lock reference, however, our delay grows not only as a function of contention but also as a function of the the length of the critical section. If a thread is executing a large critical section, all spinning threads will be increasing their delays even though the contention in the system hasn't actually increased.

## [](https://www.omscs-notes.com/operating-systems/synchronization-constructs/#queueing-lock)