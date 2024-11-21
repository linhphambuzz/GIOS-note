![[Pasted image 20241120151840.png]]

The marshaling/unmarshalling routines will all be found in the `<interface>_xdr.c` file.

In addition, the compiler will generate some cleanup operations, like `xdr_free` that will be used to free up memory regions that are allocated by the various RPC operations. These routines will typically be called within a procedure named `*_freeresult`. This is another user-defined procedure where the user can specify the pieces of state that need to be deallocated after the runtime is done servicing the RPC request. The RPC runtime will automatically call this procedure after it is done computing the results.
