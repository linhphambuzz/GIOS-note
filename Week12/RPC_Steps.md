0. Register 
	- The server must execute a registration step to let the world know what procedures it supports, what arguments it requires, and what location it can communicated with at.

1. Binding: 
	- The client finds and discovers the server that supports the functionality it needs. For connection-based protocols (like TCP/IP), the actual connection will be established in this step.
2. Call 
	- In the second step the client makes the actual RPC call. Control is passed to the stub, blocking the rest of the client.
3. Marshaling
	- The client stub then creates a data buffer, and populates it with the arguments that are passed in. This process is called **marshaling**. 
	- The arguments may located in noncontiguous memory locations within the client address space. The transport level, however, requires a contiguous buffer for transmission. This is why marshaling is needed.
	- Marshalling will  take care of the above and will place all of the info into a buffer that will be passed to a socket 
4. Sending
	- Once the buffer is available, the RPC runtime will actually send the message to the server, via whatever transmission protocol the client and server have agreed upon during the binding process.
5. Receiving 
	- The data is then received by the RPC runtime on the server machine, which performs all of the necessary checks to determine which server stub the request needs to be delivered to.
6. Unmarshall 
	- The server stub will **unmarshall** the data, extracting the necessary byte sequences from the buffer and populating the appropriate data structures.

7. Actual Call 

	- Once the arguments are allocated and set to the appropriate values, the actual procedure call can be made. This calls the implementation of the procedure that is actually part of the server process.
	- The server will compute the result of the operation, which will be passed to the server side stub and returned to the client.
![[Pasted image 20241114232115.png]]
