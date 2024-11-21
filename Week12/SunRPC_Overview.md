
![[Pasted image 20241116133710.png]]

SunRPC allows the client to interact via a procedure call interface.

### Server
- The server specifies the interface that it supports in a .x file written in XDR.
- SunRPC includes a compiler called **rpcgen** that will compile the interface specified in the .x file into language-specific stub for the client and the server.

- On start, the server process registers itself with the registry daemon available on the local machine. 
- The per-machine registry keeps track of the name of the service, the version, the protocol, and the port number. 
### Client 
-  A client must explicitly contact the registry on the target machine in order to obtain the full contact information about the desired service.

- When the binding happens, the client creates an RPC handle, which is used whenever the client makes any RPC calls. This allows the RPC runtime to track all of the RPC-related state on a per-client basis.