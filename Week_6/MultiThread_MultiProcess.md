
- An application can be implemented in a multithreaded way, which we have talked about at length. An application can also be implemented in a multiprocess way. Both strategies can be used to provide concurrency.
## Simple Web Server
![[Pasted image 20240926093034.png]]
- Some of these steps are more computationally expensive, so most of the work will be done by the CPU: The request parsing, computing header 

- Other steps require interaction with the network: accepting a connection and sending the data.

- interaction with disk: such as finding and reading the file.
