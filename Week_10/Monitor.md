- **Monitors** are a higher level synchronization construct that allow us to avoid manually invoking these synchronization operations.
- A monitor will specify:
1. a shared resource, 
2. the entry procedures for accessing that resource
3. and potential condition variables used to wake up different types of waiting threads.
- On entry: 
1. Locking , checking 

- On exit: 
1. unlock, check, signal : hidden 

When invoking the entry procedure, all of the necessary locking and checking will take place by the monitor behind the scenes. When a thread is done with a shared resource and is exiting the procedure, all of the unlocking and potential signaling is again performed by the monitor behind the scenes.

![[Pasted image 20241102120948.png]]