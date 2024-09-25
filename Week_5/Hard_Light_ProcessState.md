
![[Pasted image 20240917115046.png]]

When the operating system context switches between two kernel level threads that belong to the process, there is information relevant to both threads in the process control block, and also information that is only relevant to each thread.

Information relevant to all threads includes the virtual address mapping, while information relevant to each thread specifically can include things like signals or system call arguments. When we context switch among the two kernel level threads, we want to preserve some portion of the PCB and swap out the rest.

We can split up the information in the process control block into **hard process state** which is relevant for all user level threads in a given process and **light process state** that is only relevant for a subset of user level threads associated with a particular kernel level thread.