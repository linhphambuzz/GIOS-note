![[Pasted image 20240918084905.png]]
- The OS is intended for multiple CPU platforms and the kernel itself is multithreaded. At the user level, the processes can be single or multithreaded, and both many:many and one:one ULT:KLT mappings are supported.
- Each kernel level thread that is executing on behalf of a user level thread has a **lightweight process** (LWP) data structure associated with it
- From the user level library perspective, these LWPs represent the virtual CPUs onto which the user level threads are scheduled. 
- At the kernel level, there will be a kernel level scheduler responsible for scheduling the kernel level threads onto the CPU.

