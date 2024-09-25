![[Pasted image 20240904081308.png]]

## Definition

A **condition variable** is a construct that can be used in conjunction with mutexes to control the execution of concurrent threads.

## How it works?

- When a consumer sees that it must wait, it makes a call to the **wait** function, passing in a mutex (lock) and the condition variable it must wait on.
- The wait function must ensure that the mutex is released if the condition is not met (so that the signaling thread may acquire the mutex) and must also ensure that the mutex is acquired when the condition is met (since the wait call occurs in the middle of a critical section).
- When the condition becomes true, a thread holding the mutex may call the **signal** function to alert a waiting thread that they may proceed.

## Condition Variable API 

- We need some data structure that corresponds to the condition variable that contain 
	- mutex reference
	- list of waiting threads
- We need a **wait** procedure which takes in a mutex and a condition variable, that automatically release and reacquire if the condition occurs
- We need a **signal** procedure, which allows a thread to signal to another thread waiting on a condition that the condition has been met.
- We can also have a **broadcast** procedure, which allows a thread to signal to all other threads waiting on a condition that the condition has been met.
- ![[Pasted image 20240904082229.png]]

- The wait procedure must be able to immediately release and reacquire the mutex as necessary depending on the condition variable.
- The wait() should be implemented in an api that supports enque the thread when it goes on wait and deque it when it's time to reaccquire the mutex 
- ![[Pasted image 20240904082641.png]]

- Note that broadcast may not always be super useful. Even though we can wake up all threads in wait, since we immediately lock the mutex when we remove a thread from the wait queue, we can still only execute one thread at a time.





