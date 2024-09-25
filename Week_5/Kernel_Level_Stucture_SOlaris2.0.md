![[Pasted image 20240920134741.png]]
## Process
For each process, the kernel maintains a bunch of information, such as:

- list of kernel level threads
- virtual address space
- user credentials
- signal handlers
## LWP 
The kernel also maintains a light-weight process (LWP), which contains data that is relevant for some subset of the process. The data contained in an LWP includes: 
- user level registers: for user-level threads that are executing in the current context process
- system call arguments
- resource usage info
- signal masks

The data contained in the LWP is similar to the data contained in the ULT, but the LWP is visible to the kernel. When the kernel needs to make scheduling decisions, they can look at the LWP to help make decisions.

## Kernel-level threads
- kernel-level registers
- stack pointer
- scheduling info
- pointers to associated LWPs, and CPU structures: that associates with the kernel

**The kernel level thread has information about an execution context that is always needed**

-  There are operating system services (for example, scheduler) that need to access information about a thread even when the thread is not active. As a result, the information in the kernel level thread is **not swappable**.
- The LWP data does not have to be present when a process is not running, so its data can be swapped out. -> helps with memory foot print 

## CPU 
- current thread
- list of kernel level threads
- dispatching & interrupt handling information: how to interrupt for peripheral devcies
- Given a CPU data structure it is easy to traverse and access all the other linked data structures. In SPARC machines (what Solaris runs on), there is a dedicated register that holds the thread that is currently executing. This makes it even easier to identify and understand the current thread.

![[Pasted image 20240920134904.png]]

