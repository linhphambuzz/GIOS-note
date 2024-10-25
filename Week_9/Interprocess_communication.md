- **Inter process communication** (IPC) refers to a set of mechanisms that the operating system must support in order to permit multiple processes to interact amongst each other. This includes mechanisms related to synchronization, coordination, and communication.
- IPC mechanisms are broadly categorized as either **message-based** or **memory-based**-
- Message-based IPC mechanisms include sockets, pipes, and message queues
-  Memory-based IPC utilizes shared memory. This may be in the form of unstructured shared physical memory pages or memory mapped files which can be accessed by multiple processes.
## Remote Procedure Call
- RPC is more than just a channel for passing information between processes. 
- This method provides some additional detail as to the protocol(s) that will be used, which includes information about the data format and the data exchange procedure.

![[Pasted image 20241009133422.png]]

Finally, the need for communication and coordination illustrates the necessity of synchronization primitives.

