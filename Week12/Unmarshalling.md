- In the unmarshalling code, we take the buffer provided by the network protocol and, based on the **procedure descriptor** and the type of arguments required by the described procedure, we extract the correct chunks of bytes from the buffer and use those bytes to initialize data structures that correspond to the argument types.
- As a result of the unmarshalling process, the `i` and `j` variables will be allocated in the server address space 
- and will be initialized to values that correspond to whatever was placed into the buffer sent by the client.


![[Pasted image 20241115133423.png]]

## IDL Spec 

- The marshaling/unmarshalling routines are generally not written by the programmer. RPC systems typically include a special compiler that takes an IDL specification (i.e: procedure types and data types for the arguments) and generates the marshaling/unmarshalling routines from that.\
- The routine will then encode : converting integer from one i to another i, depends on the requirements 
- Programmer will then take relevant files for server/client when generating executable