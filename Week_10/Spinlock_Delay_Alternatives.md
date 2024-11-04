![[Pasted image 20241102203846.png]]
- This implementation introduces a delay every time the thread notices that the lock is free.
- The rationale behind this is to prevent every thread from executing the atomic instruction at the same time.
## Contention
- As a result, the contention in the system will be significantly improved. When the delay expires, the delayed threads will try to re-check the value of the lock, and it's possible that another thread executed the atomic and the delayed threads will see that the lock is busy. If the lock is free, the delayed thread will execute the atomic.
- There will be fewer cases in which threads see a busy lock as free and try to execute an atomic that will not be successful.
## Latency 

- From a latency perspective, this lock is okay. We still have to perform a memory reference to bring the lock into the cache, and then another to perform the atomic. However, this is not much different from what we have seen in the past.

## Delay 
- From a delay perspective, clearly our performance has decreased. Once a thread sees that a lock is free, we have to delay for some (seemingly arbitrary) amount of time. If there is no contention for the lock that delay is wasted time.

_________________
# Delay after each lock reference
![[Pasted image 20241102205837.png]]
- The main benefit of this is that it works on NCC architectures. Since a thread has to go to main memory on every reference on NCC architectures, introducing an artificial delay great decreases the number of reference the thread has to perform while spinning.

- Unfortunately, this alternative will hurt the delay much more, because the thread will delay every time the lock is referenced, not just when the thread detects the lock has become free.

