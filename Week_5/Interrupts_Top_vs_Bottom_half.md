
![[Pasted image 20240921161733.png]]

- When an interrupt is handled in a different thread, we no longer have to disable handling in the thread that may be interrupted. Since the deadlock situation can no longer occur, we don't need to add any special logic to our main thread.
- The **top half** of signal handling occurs in the context of the interrupted thread (before the handler thread is created). This half must be fast, non-blocking, and include a minimal amount of processing
- Once we have created our thread, this **bottom half** can contain arbitrary complexity, as we have now stepped out of the context of our main program into a separate thread.
- We're not restricted on when the bottom half will actgually be executed
- If wanting to incorpoprate complexity -> use another thread that allows to block

## Performance of Threads as Interrupts 
![[Pasted image 20240921162702.png]]

The overhead of performing the necessary checks and potentially creating a new thread in the case of an interrupt adds about 40 SPARC instructions to each interrupt handling operation.

As a result, it is no longer necessary to disable a signal before locking a mutex and re-enable the signal after releasing the mutex, which saves about 12 instructions per mutex.

Since mutex lock/unlocks occur much more frequently than interrupts, the net instruction count is decreased when using the interrupt as threads strategy.

In general, it is a solid strategy to optimize for the common case. We could have scenarios in which interrupts occur more than mutex lock/unlocks, but we have assumed this is rarely the case, and have optimized for the reverse.

