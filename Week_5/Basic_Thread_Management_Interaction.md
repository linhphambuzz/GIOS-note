
- Consider a process with four user threads. However, the process is such that at any given point in time the actual level of concurrency is two. It always happens that two of its threads are blocking on, say, IO and the other two threads are executing.
- If the operating system has a limit on the number of kernel threads that it can support, the application might have to request a fixed number of threads to support it. The application might select two kernel level threads, given its concurrency.
- When the process starts, maybe the operating system only allocates one kernel level thread to it. The application may specify (through a `set_concurrency` system call) that it would like two threads, and another thread will be allocated.
- ![[Pasted image 20240920135512.png]]
## Blocked request 

- Consider the scenario where the two user level threads that are scheduled on the kernel level threads happen to be the two that block (e.g:waiting for I/O)
- The kernel level threads block as well. (waiitning in the queue somewhere in the kernel)
-  This means that the whole process is blocked, even though there are user level threads that can make progress. The user threads have no way to know that the kernel threads are about to block, and has no way to decide before this event occur
![[Pasted image 20240920141038.png]]
- What would be helpful is if the kernel was able to signal to the user level library _before_ blocking, at which point the user level library could potentially request more kernel level threads. The kernel could allocate another thread to the process temporarily to help complete work, and deallocate the thread it becomes idle.

![[Pasted image 20240920140606.png]]

- Generally, the problem is that the user level library and the kernel have no insight into one another. To solve this problem, the kernel exposes system calls and special signals to allow the kernel and the ULT library to interact and coordinate.

`pthread_setconcurrency(int new_level)` to set the level of concurrency, if `new_level=0`, the kernel will decide for what's deemed appropriate 

