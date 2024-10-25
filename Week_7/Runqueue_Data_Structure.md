
- The runqueue data structure is only logically a queue. It can be implemented as multiple queues or even a tree. What's important is that the data structure is designed so that the scheduler can easily determine which task should be scheduled next.
- ![[Pasted image 20241006205007.png]]
## Multiqueues 

![[Pasted image 20241006211950.png]]
- One common data structure is a multi queue structure that maintains multiple distinct queues, each differentiated by their timeslice value.
- I/O intensive tasks will be associated with the queue with the smallest timeslice values, while CPU intensive tasks will be associated with the queue with the largest timeslice values.
- This solution is beneficial because it provides timeslicing benefits for I/O bound tasks, while also avoid timeslicing overheads for CPU bound tasks.
### How do you know if a task is CPU or I/O intensive? 



- We can use history based heuristics to determine what a task has done in the past as a way to inform what it might do in the future. However, this doesn't help us make decisions about new tasks or tasks that have dynamic behaviors.

## Dynamically changed Task 
![[Pasted image 20241007103956.png]]

1. When a new task enters the system, we will place it on the topmost queue (the one with the lowest timeslice). If the task yields before the timeslice has expired, we have made a good choice! 
	- We will place this task back on this queue when it becomes runnable again. If the task has to be preempted, this implies that the task was more CPU intensive than we thought, and we push it down to a queue with a longer timeslice. 
	- If the task has to be preempted still, we can push the task down even further, to the bottom queue.
2. If a task in a lower queue begins to frequently release the CPU due to I/O waits, the scheduler may boost the priority of that task and place it in a queue with a smaller timeslice.

->  **multi-level feedback queue**.
- This is not a priority queue 
-  There are different scheduling policies associated with each level.
- Importantly, this data structure provides feedback on a task, and helps the scheduler understand over time which queue a task belongs to given the makeup of tasks in the system