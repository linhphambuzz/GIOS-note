![[Pasted image 20240911112825.png]]
## Kernel Level Thread 
- Kernel level threads imply that the operating system itself is multithreaded.
- Kernel level threads are visible to the kernel and are managed by kernel level components like the kernel level scheduler. 
- The operating system scheduler will determine how these threads will be mapped onto the underlying physical CPU(s) and which ones will execute at any given point.
- Some kernel level threads may exist to support user level applications, while other kernel level threads may exist just to run operating system level services, like daemons for instance.
## User Level Thread 
- At the user level, the processes themselves are multithreaded and these are the user level threads.
- For a user level thread to actually execute, it must first be associated with a kernel level thread, and then the OS level scheduler must schedule that kernel level thread on the CPU.

