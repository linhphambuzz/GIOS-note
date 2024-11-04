
![[Pasted image 20241102165956.png]]
- From a latency perspective, this spinlock is as good as it gets. We only execute one atomic operation, and there is no way we can do better than this.
- Regarding delay, this implementation could perform well. We are continuously just spinning on the atomic. As soon as the lock becomes free, the very next call to `test_and_set` - which is the very next instruction, given that we are spinning on the atomic - will immediately detect that, and the thread will acquire the lock and exit the loop.
- From a contention perspective this lock does not perform well. As long as the threads are spinning on the `test_and_set` instruction, the processor has to continuously go to main memory on each instruction. This will delay all other CPUs that need to access memory.
_____________________
The real problem with this implementation is that we are continuously spinning on the atomic instruction. Regardless of cache coherence, we are forced to constantly waste time going to memory every time we execute the `test_and_set` instruction.

 