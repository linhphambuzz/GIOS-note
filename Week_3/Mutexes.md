![[Pasted image 20240903095514.png]]

In the above picture: 
- The snippet represents inserting a node with `value` and `ptr` to the list 
- In case `value_x` and `value_y` both wanting to insert themselves into the list, when they first read  `head_ptr(list_ptr)` it is null, so then both node x and node y will have it pointer points to Null
- To the next step, when they're both trying  to set the head pointer to point to them, only one node will get into place (race condition), the other node will simply be dangling.

## Definition
1. Mutexes 
- To support mutual exclusion, operating systems support a construct called a **mutex**. A mutex is like a lock that should be used whenever you access data/state that is _shared_ among threads 
- When a thread locks a mutex, it has exclusive access to the shared resource. Other threads attempting to lock the same mutex will not be successful. 
- These threads will be **blocked** on the lock operation, meaning they will not be able to proceed until the mutex owner releases the mutex.
- As a data structure, the mutex should have at least the following information:
	- lock status: a list of who's waiting for the lock to be released
	- owner
	- blocked threads
2. Critical section 
- The portion of the code protected by the mutex is called the **critical section**.
- The critical section should contain any code that would necessitate restricting access to one thread at a time: commonly, providing read/write access to a shared variable.
- Threads are **mutually exclusive** with respect to their execution of the critical section of the code. That is, the critical section will ever only be executed by one thread at a given moment in time.
- If `T3` reaches the lock coincides with when `T1` releases the lock, `T3` might be the one to proceed even though T2 has been waiting
\ ![[Pasted image 20240903103012.png]]
The mutex can be unlocked in two ways, depending on the implementation:

- the end of a clause following a lock statement is reached
- an unlock function is explicitly called
![[Pasted image 20240903103235.png]]

## Mutex Example 
![[Pasted image 20240903103543.png]]
- `T0` parent thread, after creating `T1`, proceed to `safe_insert()` which obtain the lock and insert 6. When it freed the lock, `T1` will obtain the lock to proceed. 