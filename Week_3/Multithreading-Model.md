## One to one model
### Pros 
- In this model, each user level thread has a kernel level thread associated with it. When a user process creates a new user level thread, either a new kernel level thread is created or an existing kernel level thread is associated with this new user level thread.
- This means that the operating system can see the user level threads. It understands that the process is multithreaded, and it also understands what those threads need. Since the operating system already supports threading mechanisms to manage its thread, the user libraries can benefit directly from the multithreading support available in the kernel.
### Cons
- One downside of this approach is that is it expensive: for every operation we must go to the kernel and pay the cost of a system call.
- Another downside is that since we are relying on the mechanisms and policies supported by the kernel, we are limited to only those policies and mechanisms.
- As well, execution of our applications on different operating systems may give different results.: portable 


![[Pasted image 20240911113609.png]]

## Many to one  model 
- In this model, all of the user level threads for a process are mapped onto a single kernel level thread. At the user level, there is a thread management library to make decisions about which user level thread to map onto the kernel level thread at any given point in time. That user level thread will still only run once that kernel level thread is scheduled on the CPU by the kernel level scheduler.
## Pros 

- The benefit of this approach is that it is portable. Everything is done at the user level, which frees us from being reliant on the OS limits and policies. 
- As well as, we don't have to make system calls for any thread-related decisions.
### Cons
- However, the operating system loses its insight into application needs. It doesn't even know that the process is multithreaded. All it sees is one kernel level thread. 
- If the user level library schedules a thread that performs some blocking operation, the OS will place the associated kernel level thread onto some request queue, which will end up blocking the entire process, even though more work can potentially be done.
### [](https://www.omscs-notes.com/operating-systems/threads-and-concurrency/#many-to-many-model)
![[Pasted image 20240911114005.png]] 

## Many to Many model 
This model allows for some user threads to have a one-to-many relationship with a kernel thread, while allowing other user threads to have a one-to-one relationship with a kernel thread.
### Pros
- The benefit is that we get the best of both worlds. The kernel is aware that the process is multithreaded since it has assigned multiple kernel level threads to the process. This means that if one kernel level thread blocks on an operation, we can context switch to another, and the process as a whole can proceed.
### Bound vs Unbound 
- We can have a situation where a user level thread can be scheduled on any allocated kernel level thread. This is known as an **unbound** thread. Alternatively, we can have the case where a user level thread will always be scheduled atop the same kernel level thread. This is known as a **bound** thread
### Cons
- One of the downsides of this model is that it requires extra coordination between the user- and kernel-level thread managers.


![[Pasted image 20240911114128.png]]
