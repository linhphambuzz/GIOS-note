
One of the attributes that are used to specify the properties of the mutex or the condition variable when they are created is whether or not that synchronization variable is private to a process or shared amongst processes.

The keyword for this is `PTHREAD_PROCESS_SHARED`. If we specify this in the attribute structs that are passed to mutex/condition variable initialization we will ensure that our synchronization variables will be visible across processes.

One very important thing to remember is that these data structures must also live in shared memory!

![[Pasted image 20241009223349.png]]
- The key is to make sure that the synchronization variable is allocated within the shared memory region that's shared among processes. 
