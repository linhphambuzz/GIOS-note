- this can be programmed quite easily with threads by adopting an attitude that device requests are all sequential (i.e. they suspend execution of the invoking thread until the request completes), and that the program meanwhile does other work in other threads.
- In general, there are four major mechanisms: **thread creation, mutual exclusion, waiting for events, and some arrangement** for getting a thread out of an unwanted long-term wait.
1. Thread creation
 - A thread is created by calling “Fork”, giving it a procedure and an argument record.
 - “Fork” returns to its caller a handle on the newly created thread.
 - The handle can be presented to a “Join” procedure. “Join” waits for the given thread to terminate, and returns the result of the given thread’s initial procedure.
 2. Mutual exclusion
- . The LOCK clause locks the mutex, then executes the contained statements, then unlocks the mutex.
3. Condition variable 
- In general a monitor consists of some data, a mutex, and zero or more condition variables