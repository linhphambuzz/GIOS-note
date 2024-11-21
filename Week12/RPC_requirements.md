1. Client/server interactions. 
- The model of IPC interactions that the RPC model is intended for needs to match client/server interactions. The server performs some complex tasks, and the client needs to know how to communicate with that server.
2. Procedure Call Interface 
- Since most of the languages at the time were procedural languages (hence the name remote _procedure_ call), there was an expectation that this model followed certain semantics.
- One goal of RPC was to simplify development of distributed applications underneath a procedure called interface -> Remote procedure call came to be 
- As a result, RPCs have synchronous call semantics :When a process makes a remote procedure call, the calling process will block until the procedure completes and returns the result. This is the exact same thing that happens when we call a procedure in a single address space. 
3. Type checking 
- If you pass an argument of the wrong type to an RPC, you will receive some kind of error.
- Type checking affords us opportunities to optimize the implementation of the RPC runtime.
- When packets are being sent between two machines, they are just a stream of bytes. Being able to transmit some information about the types can be useful when the RPC runtime is trying to interpret the bytes.
4. Cross- machine coversion 
-  there may be differences in how they represent certain data types. For instance, machine may differ in their endianness, in their representation of floating point numbers, negative numbers and so on. 
- The RPC system should hide these differences from the programmer, ensuring that the data is correctly transported and converted.
- One way to deal with the conversion is for the RPC runtime, and both endpoints to agree upon a single data representation; for example, network format of integer types. With this agreement, there is no need for endpoints to negotiate on how data should be encoded.

------------------------
Finally, RPC is meant to be more than a transport-level protocol. RPC should support different types of protocols - whether UDP, TCP or others - to communicate. RPC should also incorporate some higher level mechanisms like access control, authentication, and fault tolerance.

