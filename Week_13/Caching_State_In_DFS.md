
![[Pasted image 20241122032319.png]]


- Caching state in a DFS involves allowing clients to locally maintain a portion of the state - a file block, for example - 
- allows them to perform operations on this cached state: `open`/`read`/`write`,etc.
- Keeping the cached portions of the file consistent with the server's representation of the file requires cache coherence mechanisms.

## Coherence mechanism 

For example, two clients may cache the same portion of file. If one client modifies their local portion, and sends the update to the file server, how does the other client become aware of those changes?

For client/server systems, these coherence mechanisms may be trigged in different ways. For example, the mechanism may be triggered on demand any time a client tries to access a file, or it may be triggered periodically, or it may triggered when a client tries to open a file. In addition, the coherence mechanisms may be driven by the client or the server.


## Quiz 

![[Pasted image 20241122032859.png]]
