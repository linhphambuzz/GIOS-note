![[Pasted image 20240902150346.png]]
## Process vs. Thread 

### Process

A single-threaded process is represented by two components:

- address space (virtual <-> physical memory mapping) _code_ data  heap
- execution context _CPU registers_ stack
All of this information is represented by the operating system in a process control block

### Thread 

- Threads represent multiple independent execution contexts within the **same address space**
- They **share the virtual to physical address mapping**, as well as the code/data/files that make up the application.
- However, they will potentially be running different instructions and accessing different portions of the address space at any given time. 
- This means that each thread will have to have its own registers and stack.
![[Pasted image 20240902150848.png]]
- Each and every thread has its own data structure to represent information specific to its execution context.

- A multithreaded process will have a more complex process control block structure, as these thread specific execution contexts need to be incorporated.

## Benefit of multithreading 

- At any given time when running a multithreaded process on a multiprocessor machine, there may be multiple threads belonging to that process, each running on a given processor. While each thread is executing the _same code_ (in the sense of same source code), each thread may be executing a _different instruction_ (in the sense of different line or function) at any given time.
### Parallization  
- As a result, different threads can work in parallel on different components of the program's workload. For example, each thread may be processing a different component of the program's input. By spreading the work from one thread/one processor to multiple threads that can execute in parallel on multiple processors, we have been able to speed up the program's execution.

### Specialization 
- If we designate certain threads to accomplish only certain tasks or certain types of tasks, we can take a specialized approach with how we choose to manage those threads. 
- For instance, we can give higher priority to tasks that handle more important tasks or service higher paying customers.
- Performance of a thread depends on how much information can be stored in the processor cache (remember - cache lookups are super fast). By having threads that are more specialized - that work on small subtasks within the main application - we can potentially have each thread keep it's entire state within the processor cache (_hot cache_), further enhancing the speed at which the thread continuously performs it task.

#### So why not just write a multiprocess application?
- A multiprocess application requires a new address space and executing context for each process, while a multithreaded application requires only one address space. Thus, the memory requirements for a multiprocess application are greater than those of a multithreaded application.
- As a result, a multithreaded application is more likely to fit in memory, and not require as many swaps from disk, which is another performance improvement.


Also, passing data between processes - inter process communication (IPC) - is more costly than inter thread communication, which consists primarily of reading/writing shared variables.


### Single CPU 

- Generally, are threads useful when the number of threads exceeds the number of CPUs?

- Consider the situation where a single thread makes a disk request. The disk needs some amount of time to respond to the request, during which the thread cannot do anything useful. If the time that the thread spends waiting greatly exceeds the time it takes to context switch (twice), then it makes sense to switch over to a new thread.
![[Pasted image 20240902160030.png]]
- Now, this is true for both processes and threads. One of the most time consuming parts of context switching for processes is setting up the virtual to physical mappings. Thankfully, when we are context switching with threads, we are using the same mappings because we are within the same process. This brings down the total time to context switch, which brings up the number of opportunities in which switching threads can be useful.

## Benefit to applications and OS 

![[Pasted image 20240902160247.png]]

- By multithreading the operating system kernel, we allow the operating system to support multiple execution contexts, which is particularly useful when we do have multiple CPUs, which allows the execution contexts to operate concurrently. 
- The OS threads may run on behalf of different application or OS-level services like daemons and device drivers.


