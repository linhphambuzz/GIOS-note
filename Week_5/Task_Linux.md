- The main abstraction that Linux uses to represent an execution context is called a **task**, represented via the task structure
- A task is essentially the execution context of a kernel level thread.
- A single-threaded process will have one task, and a multithreaded process will have many tasks.
## Task Struct 
![[Pasted image 20240924213927.png]]Some of the keys indentifiers are shown here. 
- A task is identified by its `pid_t pid`
- If we have a single-threaded process the id of the task and the id of the process will be the same. If we have a multithreaded process, each task will have a different `pid` and the process as a whole will be identified by the `pid` of the first task that was created. This information is also captured in the `pid_t tgid` or task group id, field.
- The task structure maintains a list of all of the tasks for a process, whose head is identified by `struct list_head tasks`. Walking thru this list will walk thru list of task
- Linux never had one continuous process control block. Instead, the process state was always maintained through a collection of data structures referenced via pointers. We can see some of the references in the task in `struct mm_struct *mm` and `struct files_struct *files`.-> makes easy for process to share some portion of the addr space (i.e: virtual addr mapping, file)
## Task Creation: Clone

```
clone(function, stack_ptr, sharing flags,args)
```

![[Pasted image 20240924214739.png]]\
- `sharing_flags` which denotes which portion of the state of a task will be shared between the parent and child task.
- When all of the bits are set, we are creating a new thread where the state is shared with the parent thread. 
- If all of the bits are not set, we are not sharing anything, which is more akin to creating an entirely new process. 
- In fact, `fork` in Linux is implemented by `clone` with all sharing flags cleared

## Native Posix threads library 
- 1:1 model
- Kernel see all UTL info 
- traps are cheaper , so user/kernel crossings are much more affordable.
- Also, modern platforms have more memory - removing the constraints to keep the number of kernel threads as small as possible.'
