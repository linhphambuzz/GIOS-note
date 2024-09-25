
![[Pasted image 20240921160434.png]]
- To avoid the deadlock situation we covered before with regards to handler code trying to lock a mutex that the thread had already locked, perhaps it makes sense to have handler code exist in its own thread.\
- This way, when the thread tries to acquire the mutex, it will block just like any other thread, but will not deadlock. Eventually, the thread holding the mutex will release it, and the handling thread may acquire it.
## Dynamic created thread
Dynamic thread creation is expensive! Need to only create a new thread if we need it. If the handler doesn't block, execute on the interrupted thread's stack. Don't make a new thread!

To eliminate the cost of dynamic thread creation, the kernel pre-creates and -initializes thread structures for interrupt routines. This can help reduce the time it takes for an interrupt to be handled.
![[Pasted image 20240921160935.png]]
