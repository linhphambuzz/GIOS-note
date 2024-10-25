## Assumptions and Metrics 
- **Run To Completion** scheduling assumes that once a task is assigned to a CPU, it will run on that CPU until it is finished.
- For the purposes of discussion, it's necessary to make some assumptions: 
	- First, we can assume that we have a group of tasks that need to be scheduled. 
	- Second, we can assume that we know the execution times of the tasks. -
	- Third, we can assume that there is no preemption in the system.
	- Fourth, assume that there is a single CPU.

![[Pasted image 20240930195251.png]]

## First come first serve 

![[Pasted image 20240930195658.png]]

## Shortest Job First 

![[Pasted image 20240930200116.png]]
- which schedules jobs in order of their execution time.
- With this algorithm, it doesn't really make sense for the runqueue to be a FIFO queue any more. 
- We need to find the shortest task in the queue, so we may need to change our queue to be an ordered queue. 
- This makes the enqueue step more laborious. Alternatively, we can use a tree structure to maintain the runqueue. 
- Depending on how we rebalance the tree every time we add a new task, we can easily find the node containing the shortest job. The runqueue doesn't have to be queue!


