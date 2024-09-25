## What do we need to support thread?
1. Thread data structures 
- Identify the thread
- Keep track of usage 
2. mechanism to create and mng 
3. mechanism to safely coordinate among thread 

## Data race

- Process: When processes run concurrently, they operate within their own address space. The operating system ensures that physical access from one address space never touch memory mapped to by another process's address space.
- Thread: Threads share the same virtual to physical address mappings, since they share the same address space. Naturally, this can introduce some problems. (i.e:T1 and T2 might both try to write on x)

![[Pasted image 20240902162317.png]]
For example, one thread can try to read the data while another modifies it, which can lead to inconsistencies. This is an example of a **data race** problem.\

## Mutual exclusive

This is a mechanism by which only one thread at a time is granted access to some data. The remaining threads must wait their turn. We accomplish mutual exclusion through the use of a **mutex**.

## Condition Variables 

a mechanism by which a thread can wait on another thread, and to be able to exactly specify what condition the thread is waiting on. For this inter thread communication, we may use a construct called a **condition variable**.


Both _mutexes_ and _condition variables_ are examples of **synchronization mechanisms** 

