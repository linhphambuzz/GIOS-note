When an I/O request is made, the user process typically requires some type of response from the device, even if it just an acknowledgement.

What happens to a user thread once an I/O request is made depends on whether the request was synchronous or asynchronous.

## Synchronous 
For synchronous operations, the calling thread will block. The OS kernel will place the thread on the corresponding wait queue associated with the device, and thread will eventually become runnable again when the response to its request becomes available.
## Asynchronous 
With asynchronous operations, the thread is allowed to continue as soon as it issues the request. At some later time, the user process can be allowed to check if the response is available. Alternatively, the kernel can notify the process that the operation is complete and that the results are available.


![[Pasted image 20241104174505.png]]

Remember when we talked about Flash, we discussed that the implementation mimicked asynchronous I/O by delegating all I/O calls to special helper threads. Here we are talking about true, OS-supported asynchronous I/O.

