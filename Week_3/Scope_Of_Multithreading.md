
![[Pasted image 20240911121901.png]]

## Kernel Level 
At the kernel level, there is system wide thread management, supported by the operating system level thread managers. These managers will look at the entire platform before making decisions on how to run their threads. This is the **system scope**.
## User Level 
On the other hand, at the user level, the user level library manages all of the threads for the given process it is linked to. The user level library thread managers cannot see threads outside of their process, so we say that these managers have **process scope**.

## Example of different scope 
- To understand the consequences of having different scope, let's consider the scenario where we have two processes, A and B. A has twice as many user level threads as B.
- 
- 
1. Process Scope 
- *If the threads have a process scope*, this means that the kernel cannot see them, and will probably allocate equal kernel resources to A and B. This means that a given thread in A will be allocated half of the CPU cycles as will be allocated to a thread in B.
![[Pasted image 20240911122654.png]]
2. System Scope 
- If we have a system scope, the user level threads will be visible at the kernel, so the kernel will allocate the CPU relative to the total amount of user threads, as opposed to the total amount of processes. In the case of A and B, if the threads in these processes have a system scope, A will most likely be allocated twice the number of kernel level threads as B.
![[Pasted image 20240911122752.png]]