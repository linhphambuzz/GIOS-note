- Semaphore acts as a traffic light: allow them to go and block them 
- Similar to a mutex.. but more general 
- represented by positive int values 
## Mechanism 
- Threads arriving at a semaphore with a nonzero value will decrement the value and proceed with their execution. 
- Threads arriving at a semaphore with a zero value will have to wait. 
- ![[Pasted image 20241102105404.png]]
- 

## Benefit 
- As a result, the number of threads that will be allowed to proceed at a given time will equal the initialization value of the semaphore.