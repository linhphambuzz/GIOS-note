
## Problems with O(1) Scheduler 

- One problem with the O(1) is that once a task enters the expired queue, it will not get a chance to run again until all other tasks in the active queue have executed for their timeslices. This is a problem for interactive tasks, introducing jitter into interactions that should appear seamless.
- In addition, the scheduler in general doesn't make any **fairness** guarantees. Intuitively, fairness is the concept that in a given time interval, a task should be able to run for an amount of time that is relative to its priority.
- the CFS scheduler was introduced. CFS is now the default scheduler for non-realtime tasks in Linux.


## Run Queue 
- CFS uses a **red-black tree** as a runqueue structure. Red black trees are self-balancing trees, which ensure that all of the paths from the root of the tree to the leaves are approximately the same size.
- Tasks are ordered in the tree based on the amount of time that they spent running on the CPU, a quantity known as **vruntime** (virtual runtime). CFS tracks this quantity to the nanosecond.
- This runqueue has the property that for a given node, all nodes to the left have lower vruntimes and therefore need to be scheduled sooner, while all nodes to the right, have larger vruntimes and therefore can wait longer.


## CFS Scheduling 


- The CFS algorithm always schedules the node with the least amount of vruntime in the system, which is typically the leftmost node of the tree.
- Periodically, CFS will increment the vruntime of the task that is currently executing on the CPU, at which point it will compare this vruntime with the vruntime of the leftmost task in the tree.
- If the currently running task has a smaller vruntime than the leftmost node, it will keep running; otherwise, it will be preempted in favor of the leftmost node, and will be inserted appropriately back into the tree.
## Task Priorities 

- To account for differences in task priorities : CFS changes the effective rate at which the virtual time progresses 
- For lower priority tasks, time passes more quickly, the vruntimes progresses faster then they're more likely to lose CPU more quicker. 
- Rate is slower for higher priority task, they'll have much more time 
- CFS uses one run queue structure
![[Pasted image 20241007204207.png]]

## Summary 

In summary, task selection from the runqueue takes constant time. Adding a task to the runqueue takes log time relative to the total number of tasks in the system.
![[Pasted image 20241007205543.png]]