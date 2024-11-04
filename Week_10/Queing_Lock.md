
- The reason for introducing a delay is to guard against the case where every thread tries to acquire a lock once it is freed. 
- Alternatively, if we can prevent every thread from seeing that the lock has been freed _at the same time_, we can indirectly prevent the case of all threads rushing to acquire the lock simultaneously.
## Queing Lock 
- The lock that controls which thread(s) see that the lock is free at which time is the **queuing lock**.
- The queueing lock uses an array of flags with up to `n` elements, where `n` is the number of threads in the system.
- Each element in the array will have one of two values: either `has_lock` or `must_wait`.
- In addition, one pointer will indicate the current lock holder (which will have a value of `has_lock`), and another pointer will reference the last element on the queue.
![[Pasted image 20241103210250.png]]
- When a new thread arrives at the lock, it will receive a ticket, which corresponds to the current position of the thread in the lock. This will be done by adding it after the existing last element in the queue.
- Since multiple threads may enter the lock at the same time, it's important to increment the `queuelast` pointer atomically. This requires some support for a `read_and_incremement` atomic.
## Thread arrived at the lock
- ![[Pasted image 20241103210503.png]]
- For each thread arriving at the lock, the assigned element of the flags array at the ticket index acts like a private lock. As long as this value is `must_wait`, the thread will have to spin. When the value of the element is becomes `has_lock`, this will signify to the threads that the lock is free and they can attempt to enter their critical section.

- When a thread completes a critical section and needs to release the lock, it needs to signal the next thread. Thus `queue[ticket + 1] = has_lock`.

## Drawbacks 
- This strategy has two drawbacks. First, it requires support for the `read_and_increment` atomic, which is less common that `test_and_set`.

- In addition, this lock requires much more space than other locks. All other locks required a single memory location to track the value of the lock. This lock requires `n` such locations, one for each thread.

