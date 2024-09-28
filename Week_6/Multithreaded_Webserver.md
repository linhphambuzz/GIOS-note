![[Pasted image 20240926093521.png]]
- In this diagram, every thread is performing all of the steps. Of course, we could have a boss/workers setup where the boss runs the first step and the workers execute the remaining steps. We could also have a pipeline setup, in which multiple threads execute one step and one step only.
### Pros 
- The benefits of this approach are that we have a shared address space, shared state, and a cheap user level context switch. Memory requirements are lighter, since we have a lot of shared information across all threads in the process.
### Cons 

- The downside of this approach is that it is not a simple implementation. Multithreaded programs require explicit application level synchronization code, which can add to the overall complexity of the application. 
- In addition, a multithreaded approach depends on underlying operating system level support for threads, although this is less of an issue now than it was in the past.