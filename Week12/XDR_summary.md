
![[Pasted image 20241116141511.png]]
- RPC run times reduces the need for dev to manually create buffer, socket, etc..

## note for multithreading 

![[Pasted image 20241116141718.png]]

By default, `rpcgen` generates code that is not thread safe. To generate thread safe code use:

```
rpc_gen -C -M <interface>.x
```

The `-M` flag doesn't actually give a multithreaded server, rather it ensures that the code produces will be thread safe.

To actual generate a multithreaded server, you can pass the `-A` flag on Solaris. In Linux, a multithreaded server needs to be implemented manually.

