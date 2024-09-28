- When we talked about the many-to-one user level thread to kernel level thread model, we saw that a user level thread that blocks will block the entire process.

-> A similar problem can occur in the event driven model. If one of the handlers initiates a blocking call, the entire process can be blocked.

## Asynchronous I/O operation
![[Pasted image 20240926105019.png]]
-  In asynchronous system calls, when the system call is made, the operating system obtains all of the relevant information from the stack, and either learns where to return results, or tells the caller where to get results later. Asynchronous calls let the process or thread continue execution now and check their results later.
- Asynchronous calls require a multithreaded kernel. While the caller thread continues execution, another kernel thread must do all the waiting that is needed to get the I/O results. Asynchronous operations can also benefit from the hardware devices. For example, a thread can pass a request over to a device and the device can let the calling thread know at a later time the results of its request.

- The takeaway is that when we perform asynchronous I/O operations, our thread will not be blocked in the kernel while the I/O operation actually takes place.

## Helper 

- When the handler needs to initiate an I/O operation that can block, the handler passes the call to the operation to a helper, and returns to the event dispatcher.
- The helper will be the one that handles the blocking I/O operation and interact with the event dispatcher as necessary.
- the communication with the helper can be with sockets or pipes, which both present a file descriptor like interface
- In doing this, the synchronous I/O call is handled by the helper. The helper will block, but the main event loop will not!
- Although we don't have asynchronous system calls, we can fake it to an extent by delegating blocking calls to processes.\
- ![[Pasted image 20240926105813.png]]
### Asymmetric MultiProcess Event Driven Model (AMPED)
- It is multiprocess, each of the helper run in one process
- Asymmetric because helper is for blocking IO, main one do everything else 
![[Pasted image 20240926122158.png]]

## AMTED 
- When the helpers are threads, not processes 

## Pros of AMPED/ AMTED 
-  Resolves the portability of pure event-driven model: asynchronous, I/O calls, and threading support which requires OS support 
- Achieve concurrency with less footprint: in multiprocesses, mt, each worker has to perform a full req so its requirements for memory usage is large
- The helper entities are there only for IO blocking operations, whereas MP and MT requires as many processes/threads as there are requests

## Cons
- not as wide applciable
- problems with routing
- 