
- When a thread is created, the library returns a t**hread id.** This id is not a direct pointer to the thread data structure but is rather an index into an array of thread pointers.
- The nice thing about this is that if there is a problem with the thread, the value at the index can provide meaningful info messages instead of the pointer just pointing to some corrupt memory.


The **thread data structure** contains different fields for:

- execution context
- registers
- signal mask
- priority
- stack pointer
- thread local storage: for local thread var that's known as compiled time 
- stack


The amount of memory needed for a thread data structure is often almost entirely known upfront. This allows for compact representation of threads in memory: basically, one right after the other in a contiguous section of memory.


![[Pasted image 20240918090413.png]]
- However, the user library **does not control stack growth.** With this compact memory representation, there may be an issue if one thread starts to overrun its boundary and overwrite the data for the next thread. If this happens, the problem is that the error won't be detected until the overwritten thread starts to run, even though the cause of the problem is the overwriting thread.
- The solution is to separate information about each thread by a **red zone**. The red zone is a portion of the address space that is not allocated. If a thread tries to write to a red zone, the operating system causes a fault. Now it is much easier to reason about what happened as the error is associated with the problematic thread.