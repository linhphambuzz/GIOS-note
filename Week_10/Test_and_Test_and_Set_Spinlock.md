
The problem with the previous implementation is that all of the CPUs are spinning on the atomic operation. Let's try to separate the test part - checking the value of the lock - from the atomic. 
The intuition is that CPUs can potentially test their cached copy of the lock and only execute the atomic if it detects that its cached copy has changed.
![[Pasted image 20241102170214.png]]

- First we check if the lock is busy. Importantly, this check is performed against the cached value. As long as the lock is busy, we will stay in the while loop, and we won't need to evaluate the second part of the predicate. Only when the lock becomes free - when `lock == busy` evaluates to false - do we actually execute the atomic.
- This spinlock is referred to as the **test-and-test-and-set spinlock**. It is also called a spin-on-read or spin-on-cached-value spinlock.
## Latency & Delay
From a latency and delay standpoint, this lock is okay. It is slightly worse than the test-and-set lock because we do have to perform this extra step.
## Contention 

- If we don't have a cache coherent architecture, there is no difference in contention. Every single memory reference will go to memory.
- If we have cache coherence with the write-update strategy, our contention improves. The only problem with write-update is that all of the processors will see the value of the lock as free and thus all of them will try to lock the lock at once.
- If we have cache coherence with the write-invalidate strategy, our contention is terrible. Every single attempt to acquire the lock will generate contention for the memory module and will also create invalidation traffic.
![[Pasted image 20241102171041.png]]

----------------------
One outcome of executing an atomic instruction is that we will trigger the cache coherence strategy regardless of whether or not the value protected by the atomic changes.
- If we have a write-update situation, that coherence traffic will update the value of the other caches with the new value of the lock. If the lock was busy before the write-update event, and the lock remains busy after the write-update event, there is no problem. The CPU can keep spinning on the cached copy.
- However, write-invalidate will invalidate the cached copy. Even if the value hasn't changed, the invalidation will force the CPU to go to main memory to execute the atomic. What this means is that any time another CPU executes an atomic, all of the other CPUs will be invalidated and will have to go to memory.

![[Pasted image 20241102202533.png]]