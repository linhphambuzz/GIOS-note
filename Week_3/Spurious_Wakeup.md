
- In this case, the writer is locking the mutex after writing to the shared state. Once the mutex is acquired, the proxy variable is updated, and a broadcast and signal are sent
- When the broadcast is issued, the thread library can start removing reader threads from the wait queue for their condition variable, potentially even before the writer releases the mutex.
- as the readers are removed from this queue is that they will try to acquire the mutex. Since the writer has not yet released the mutex, none of the readers will be able to acquire the mutex
- They will have been woken up from one queue (associated with the condition variable) only to be placed on another queue (associated with acquiring the mutex) -> **spurious wake up**
- Note that spurious wake ups will not affect the correctness of the program, but rather the performance, as cycles will be wasted context switching to threads that will just be placed back on another queue.

![[Pasted image 20240911110350.png]]


Often we can unlock the mutex before we signal or broadcast. 

![[Pasted image 20240911110729.png]]

Sometimes we cannot. For example, if we signal/broadcast conditionally depending on some property of the shared state, that property must be accessed from within the mutex, which means the signal or broadcast must also take place within the mutex.

![[Pasted image 20240911110834.png]]- 
