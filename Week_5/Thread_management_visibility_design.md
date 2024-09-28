
The kernel sees:

- Kernel level threads
- CPUs
- Kernel level scheduler

The user level library sees:

- User level threads
- kernel level threads that are assigned to that process 


## Bound threads/ Pinning 
- The user level library can request that one of its threads be bound to a kernel level thread. This means that this user level thread will always execute on top of a specific kernel level thread. This may be useful if in turn the kernel level thread is pinned to a particular CPU.

## Visibility bw kernel and UL library 
![[Pasted image 20240920142558.png]]

- If a user level thread acquires a lock while running on top of a kernel level thread and that kernel level thread gets preempted, the user level library scheduler will cycle through the remaining user level threads and try to schedule them. If they need the lock, none will be able to execute and time will be wasted until the thread holding the lock is scheduled again.

![[Pasted image 20240920142443.png]]

- The user level library will make scheduling changes that the kernel is not aware of which will change the ULT/KLT mapping in the many to many case. Also, the kernel is unaware of the data structures used by the user level, such as **mutexes and wait queues.**->We should look at 1:1 ULT:KLT models

## User- level library

![[Pasted image 20240920143058.png]]
The User-level library is part of the user's process, part of its addr space. Occasional prog counter will jump to this addr space. 
The control is passed to the user level library scheduler when:

- ULTs explicitly yield
- Timer set by the UL library expires
- Synchronization takes place: ULTs call library functions like lock/unlock
- blocked threads become runnable

The library scheduler may also gain execution in response to certain signals from timers and/or the kernel.
