![[Pasted image 20241114230707.png]]
## Client
- With RPC, the client is still allowed to call the function `add` with `i` and `j`, even those the client doesn't hold the implementation of the `add` function.
- In a regular program, when a procedure is called, the execution jumps to some other point in the address space where the implementation of that procedure is actually stored. In this example, when the client calls `add`, the execution will also jump to another location in the address space, but it won't be where the implementation of `add` lives. Instead, it will be in a **stub** implementation. To the rest of the process, this stub will look like the real `add`.
- The responsibility of the client stub is to create a buffer and populate that buffer with all of the appropriate information 
- After the buffer is created, the RPC runtime sends the buffer to the server process. This may be via TCP/IP sockets or some other transport-level protocol.
- The stub code itself is automatically generated via some tools that are part of the RPC package; that is, the programmer doesn't have to write the stub code.

- The RPC runtime also uses the server information to establish the connection with the client and to carry out all of the communication.


## Server 

- When the packets are received on the server, they are handed off to the server stub. This stub knows how to parse all of the received bytes, and it will be able to determine that this is an RPC request for `add` with the arguments `i` and `j`.
- Once this information is extracted, the stub is ready to make a call in the server process to the local `add` function with `i` and `j`
- The server will then create a buffer for the result and send it back to the client via the appropriate connection. The packets will be received by the client stub, and the information will be stored in the client address space.

- Finally, the client function will return. The result of the call will be available, and client execution will proceed.

- Note that when the client's waiting for the result back from the server, it'll be blocked 