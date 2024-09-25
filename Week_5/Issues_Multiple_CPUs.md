-  In a multi CPU system, the kernel level threads that support a process may be running concurrently on multiple CPUs. We may have a situation where the user level library that is operating in the context of one thread on one CPU needs to somehow impact what is running on **another** CPU.
![[Pasted image 20240920145120.png]]

- Currently, T2 is holding the mutex and is executing on one CPU. T3 wants the mutex and is currently blocking. T1 is running on the other CPU.
- At some point, T2 releases the mutex, and T3 becomes runnable. T1 needs to be preempted, to context switch to T3
- We can't change the CPU register of 1 CPU on another CPU
- We need to send a signal from the context of one thread on one CPU to the context of the other thread on the other CPU, to tell the other CPU to execute the library code locally, so that the proper scheduling decisions can be made.
- Once the signal occurs, the user level library code on the 2ns CPU can block T1 and schedule T3, keeping with the thread priorities within the application.

