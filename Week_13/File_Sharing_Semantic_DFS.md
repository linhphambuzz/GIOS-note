![[Pasted image 20241122033135.png]]
## Single node
- Whenever a file is modified by any process, that change is immediately visible to any other process in the system. This will be the case even if the change isn't pushed out to disk because both processes have access to the same buffer cache.

## DFS

- Even if a write gets pushed to the file server immediately, it will take some time before that update is actually delivered to the file server. 
- It is possible that another client will not see that update for a while, and every time it performs a read operation it will continue seeing "stale" data. 
- Given that message latencies may vary, we have no way of determining how long to delay any possible read operation in order to make sure that any write from anywhere in the system arrives at the file servers so that we can guarantee no staleness.
- -> in order to maintain acceptable performance, a DFS will typically sacrifice some of the consistency, and will accept more relaxed file sharing semantics.

## Session Semantics 
- The client writes back to the server whatever data was modified on `close`
- Whenever a client needs to `open` a file, the ocal cache is skipped, and the client goes to the server and checks to see if a more recent version is present on the file server.
- One session is the period between when the file is open til when it's closed. 
- With session semantics, it is very possible for a client to be reading a stale version of a file. However, we know that when we close a file or open a file that we are consistent with the rest of the filesystem at that moment.
- Session semantics are easy to reason about, but they are not great for situations where clients want to concurrently share a file. For example, for two clients to be able to write to a file and see each other's updates, they will constantly need to `close` and re-`open` the file. Also, files that stay open for longer periods of time may become severely inconsistent.

## Periodic Updates

- In order to avoid long periods of inconsistency, the client may write back changes periodically to the server. In addition, the server can send invalidation notifications periodically, which can enforce time bounds on inconsistency. Once the server notification is received, a client has to sync with the most recent version of the file.

- The filesystem can provide explicit operations to let the client `flush` its updates to the server, or `sync` its state with the remote server. Since the client doesn't necessarily know about the update period of the server



![[Pasted image 20241122035011.png]]


## Other Strategies 

- With immutable files, you never modify an old file, but rather create a new file instead.

- With transactions, the filesystem exports some API to allow clients to group file updates into a single batch to be applied atomically.

## Quiz

![[Pasted image 20241122035911.png]]

- Server-driven: server sends out invalidate