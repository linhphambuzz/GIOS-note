![[Pasted image 20241115134955.png]]
- In regular local procedures, it makes sense to allow pointer arguments. The pointer references some address within the address space of both the calling procedure and the called procedure, so the pointer can be dereferenced with no issue.
- In RPC, this makes no sense. The pointer points to some particular data in the caller address space, and some arbitrary data in the remote address space.

-----

To solve this problem, an RPC system can disallow pointers to be used an arguments to any RPC procedure.

Another solution allows pointers to be used, but ensures that the referenced data - not the pointer - is marshaled into the transmitted buffer.

On the server side, once the data is unpacked, the unmarshalling code will pass the address of this data to the local procedure.

In this way, RPC allows pointers to be "passed" between the client and the server.

