We need some data structure to represent a thread
The information we need to describe a thread may include:
	- Thread ID
	- Program counter
	- Stack pointer
	- Register values
	- Stack
	- Other attributes (priority attributes, etc.)
1. To create a thread
- To create a thread, think of a `fork` (not the UNIX fork) call which takes two arguments: the `proc` to run when the thread is created, and the `args` to pass to `proc`
- When one thread calls `fork(proc,args)` a new thread is created, with a new data structure and its program counter pointing to the first argument of `proc`. And these` args` will be available on the stack of the thread.  
- ![[Pasted image 20240902190408.png]]

- After the fork completes, the process now has two threads both of which can execute concurrently.
- When the forked thread completes, we need some mechanism by which it can return its result or communicate its status to the forking thread.
- On the other hand, we need to ensure that a forking thread (t0) does not exit before its forked thread(t1) completes work (as child threads exit when parent threads do).
-  When the parent thread calls `join` with the thread id of the child it will be blocked until the child thread is finished processing.
-  `join` returns the result of the child's computation. When `join` returns, the child thread exits the system and all resources associated with it are deallocated.
- Except from `join`, in others aspect, the children and the parents are equivalent in allocating resources that are availble thru the process as a whole (hardware, CPU, or actual states within the process)

## Thread Creation example

![[Pasted image 20240903094134.png]]
	1. `thread1`  is created by T0 with a shared_list `list`
	2. in `fork`, T1 is to do an insert of 4 into the shared_list
	3. after the fork, there's a command to insert 6 into the shared_list 
	4.  because we do not know which thread will run at which time in this example, we cannot be certain of the ordering of the elements in the list.
	5. Perhaps the child thread inserts its element before the parent thread, or perhaps the parent thread inserts first. This is a concrete example of the _data race_ described above.\
	6. Then the call to `join()`, this call is optional because the list is shared. It doesn't matter if parents T0 is waiting for T1 or not, the appending wouldn't be interrupted. This is because the result of child's ops is available thru the shared list


