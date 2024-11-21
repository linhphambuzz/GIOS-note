## Definition 

**Binding** is the mechanism used by the client to determine which server to connect to, based on the service name and the version number. In addition, binding is used to determine how to connect to a particular server; basically, to discover the IP address and/or network protocol required for the client/server connection to be established.

## Registry 

![[Pasted image 20241115134319.png]]

### Definition 
- To support binding, there needs to be some systems software that maintains a database of all available services. This is often called a **registry**.

- A registry is essentially the yellow pages for services: you pass the registry the name of the service and the version you are looking for, and you receive the contact information for the matching server. This contact information will include the IP address, port, and transport protocol.
### distributed online platform


At one extreme, this registry can be some distributed online platform where any RPC service can register.

### dedicated process

On the other hand, the registry can be a dedicated process that runs on every server machine and only knows about the processes running on that machine. In this case, clients must know the machine address of the host running the service, and the registry need only provide the port number that the service is running on.

### naming protocol 
The registry needs some sort of naming protocol. The simplest approach requires that the client specifies the exact name and version number of the service it requires. A more sophisticated naming scheme may be able to consider synonyms. In this case, requesting the `sum` service might still get you the `add` service.

