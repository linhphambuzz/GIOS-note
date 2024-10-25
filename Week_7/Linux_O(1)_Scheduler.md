## Linux O(1)
- The Linux O(1) scheduler gets its name from the fact that it can add/select a task in constant time, regardless of the number of tasks in the system.
- It is a preemptive, priority-based scheduler, with 140 priority levels. 
- The priority levels are broken into two classes: priorities from 0 to 99 are for real-time tasks, while 100 - 139 are for timesharing tasks.
### User Processes 

- User processes have priorities in the timesharing class, with the default priority in the middle at 120
- Priority levels can be adjusted with so-called **nice values** which span from -20 to 19, corresponding to 120 - 20 to 120 + 19. 
- There is a system call to adjust the priority of a user process.

### Timeslice Value 

- The O(1) scheduler borrows from the MLFQ scheduler in that each priority level is associated with a different timeslice value.
- The scheduler assigns the smallest timeslice values to the low-priority, CPU bound tasks, and assigns the largest timeslice values to the more interactive tasks.

### Feedback 

- As well, the O(1) scheduler uses feedback from how tasks behaved in the past in order to understand how to prioritize tasks in the future.
- The feedback for the task depends on how long the task spent sleeping during its timeslice.
- Sleeping refers to time spent idling or waiting. If a task spends more time sleeping, this means it is a more interactive tasks, and its priority is boosted (priority - 5). 
- If a task spends less time sleeping, this means it is a more computationally intensive task, and its priority is lowered (priority + 5).

![[Pasted image 20241007104913.png]]

### Run Queue
- The runqueue in the O(1) scheduler is implemented as two arrays of tasks. Each array elements points to the first runnable task at that priority level.
![[Pasted image 20241007195630.png]]
#### Active list 
- The active list is the primary one that the scheduler uses to select the next task to run. I
- It takes constant time to add a task, as it takes constant time to index into the array and then follow the pointer to the end of the task list to enqueue the task. It
-  It takes constant time to select a task because the scheduler relies on certain instructions that return the first set bit in a sequence of bits.
- If the sequence of bits corresponds to the priority levels, and a set bit means that there are tasks at that level, then it will take a constant amount of time to run those instructions to detect what is the priority level that has certain tasks on it.
- Once that position is known, it takes a constant amount of time to index into the array and select the first task from the task list.
- If a task yields the CPU to wait on an event or is preempted due to a higher priority task becoming runnable, the time it has spent on the CPU is compared to the timeslice. If it is less than the timeslice, the task is placed back on the active queue for that priority level.

### Inactive list 

Only after the entire timeslice has been exhausted will the task move to the expired array. The expired array contains the inactive tasks. This means that the scheduler will not schedule tasks from this array while there are still tasks in the active array. Once there are no more tasks in the active array, the empty and the active array will be swapped.

### Priority vs. Timeslice 
- In this case, however, giving the lowest priority tasks the smallest timeslices ensures that low priority tasks - which only run after all higher priority tasks expire - do not block the higher priority tasks for too long. The lower priority tasks get their small window to accomplish their work, and then quickly yield back to more important tasks.


The O(1) scheduler was introduced in Linux 2.5. Despite its constant time add/select functionality, though, this scheduler was not performant enough to keep up with the realtime needs of new applications, like Skype, for instance. For this reason, the O(1) scheduler was replaced by the **completely fair scheduler** (CFS) in Linux 2.6.23, which is now the default scheduler.

