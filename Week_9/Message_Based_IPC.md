- In messaged-based IPC, processes create messages and then send and receive them. The operating system is responsible for creating and maintaining the channel that is used to send these messages.
- The OS provides an interface to the processes so that they can send messages via this channel. The processes send/write messages to a port, and then recv/read messages from a port. The channel is responsible for passing the message from one port to the other.
- ![[Pasted image 20241009133629.png]]
-Since the OS is required to establish the communication and perform each IPC operation, every send and receive call requires a system call and a data copy.
When we send, the data must be copied from the process address space into the communication channel. When we receive, the data must be copied from the communication channel into the process address space.
![[Pasted image 20241009133727.png]]
- This means that a request-response interaction between two processes requires a total of four user/kernel crossings and four data copying operations. These overheads are one of the negatives of message-based IPC.
## Pros and COns

One of the positives of this approach is its relative simplicity. The OS kernel will take care of all of the operations regarding channel management and synchronization.

## Forms of Message Pasiing

### Pipes
- Pipes are characterized by two endpoints, so only two processes can communicate via a pipe. T
- . There is no notion of a message with pipes; instead, there is just a stream of bytes pushed into the pipe from one process and read from the pipe by the other process.
### Message Queue
- Messages queues understand the notion of messages that they can deliver. A sending process must submit a properly formatted message to the channel, and then the channel can deliver this message to the receiving process.
![[Pasted image 20241009134323.png]]

### Socket 

![[Pasted image 20241009134449.png]]
- With sockets, processes send and receive messages through the socket interface. The socket API supports `send` and `recv` operations that allow processes to send message buffers in and out of the kernel-level communication buffer.
- The `socket` call itself creates a kernel-level socket buffer. In addition, it will associate any kernel level processing that needs to be associated with the socket along with the actual message movement.

For instance, the socket may be a TCP/IP socket, which means that the entire TCP/IP protocol stack is associated with the socket buffer.

Socket-based communication can happen between processes on different machines! If the process are on different machines, then the communication buffer is really between the process and the network device that will actually send the data.

## [](https://www.omscs-notes.com/operating-systems/inter-process-communication/#shared-memory-ipc)