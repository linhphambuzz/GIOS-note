In a **Networking File System** (NFS), clients access files across the network, hence the name.
![[Pasted image 20241122072034.png]]

## Client Request

Clients request and access files via the VFS, using the same types of file descriptors and operations that they use to access files in their local storage. The VFS layer determines if the file belongs to the local filesystem or whether the request needs to be pushed to the NFS client so that it can be passed to the remote filesystem.

## Request passing to Server 

The NFS client interacts with the NFS server via RPC. The NFS server receives the request, forms it into a proper filesystem operation that is delivered to the local VFS. From there, the request is passed to the local file system interface. On the server machine, requests coming from the NFS server look identical to filesystem requests coming from any other application running on the server machine.

## File handler

When an `open` request comes to an NFS server, it will create a file handle. This file handle will contain information about the server machine as well as information about the file. This handle will be returned back to the client machine. Whenever the client wants to access files via NFS, it can pass this handle. If the file is deleted or the server machine dies, this handle becomes stale.

