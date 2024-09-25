![[Pasted image 20240911104520.png]]
- If we consider the reading and writing of the data to be the protected operations of the above application, then those sections of code are really the critical sections of our application, even though they exist outside of a mutex block.
![[Pasted image 20240911104852.png]]
The structure of our application is such that even though the critical operations are not governed by a mutex, entering and exiting from those operations is.
![[Pasted image 20240911104916.png]]
- For example, before we can read data, we must first lock the mutex and increment `resource_counter`. After we read data, we must again lock the mutex and decrement `resource_counter`. A similar setup exists for writing data.
- Each time we acquire the mutex, we must ensure that a condition is met such that we can proceed safely. If the condition is not met, we must wait. Once the condition is met, we can update our proxy variable. If appropriate, we can signal/broadcast to other threads if some condition has changed. Finally we can unlock the mutex.
- 
Enter and Exit Critical :
![[Pasted image 20240911105024.png]]
- The "enter critical section" blocks can be seen as a higher level "lock" operation, while the "exit critical section" blocks can be seen as a higher level "unlock" operation, even though a mutex is being locked and unlocked within each of those blocks.