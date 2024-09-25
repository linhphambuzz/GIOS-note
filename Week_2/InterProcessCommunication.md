Can processes interact? YES! It is common today that an application consists of multiple processes, so it is important that one process can talk to another.

## Webserver Example
- Web server running in one process, database running in another. 
- Server: accept req. 
- Database: stores info
- Each has a seperated address space 
## Interprocess communication mechanism 

- These mechanisms help to transfer data/information between address spaces while maintaining protection and isolation. 
- There are many different types of inter process communication, so these mechanisms needs to be flexible and performant.

## Message Passing IPC 
- Operating system establishes a communication channel - like a shared buffer, for instance - and the processes use that to communicate. 
- One process can write/send through the channel, while the other can read/recv from the channel.
- ![[Pasted image 20240829131508.png]]
- Pros: 
	- The OS manages the channel,  and already has the system calls in place for write/send and read/recv.
- Cons: Downsides are overhead. Every single piece of information to be transmitted needs to be copied from address space of sending process into memory allocated to the kernel, and then finally into the address space of the receiving process.

## Shared Memory IPC 

- The operating system establishes a shared memory channel, and then maps it into the address space of both processes.
- The processes are then allowed to directly read/write to this memory the same way they can read/write from any memory allocated to them in their address space.
- The operating system is completely out of the picture in this case, which is the main benefit!
- ![[Pasted image 20240829131922.png]]
- Cons: The disadvantage to this approach is that because the OS is out of the way, a lot of the APIs that were taken for granted in message passing IPC have to be reimplemented.

### Shared data or Message passing 

- Shared data: cheap because no kernel ops. involved. But mapping memories between processes are expensive