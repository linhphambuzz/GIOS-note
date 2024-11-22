![[Pasted image 20241121154818.png]]
## Stateless 
A **stateless** server keeps no state.

It has no notion of:

- which files/blocks are being accessed
- which operations are being performed
- how many clients are accessing how many files

-> As a result, every request has to be completely self-contained. This type of server is suitable for the extreme models, but it cannot be used for any model that relies on caching. Without state, we cannot achieve consistency management. In addition, since every request has to be self-contained, more bits need to be transferred on the wire for each request.

### Benefit

One positive of this approach is that since there is no state on the server, there is no CPU/memory utilization required to manage that state. Another positive is that this design is very resilient. Since requests cannot rely on any internal state, the server can be restarted if it fails at no detriment to the client.


## Stateful 

A **stateful** server maintains information about:

- the clients in the system
- which files are being accessed
- which types of accesses are being performed
- which clients have a file cached
- which clients have read/written the file

 Because of the state, the server can allow data to be cached and can guarantee consistency. In addition, state management allows for other functionality like locking. Since accesses are known, clients can request relative blocks ("next kB of data") instead of having to specify absolute offsets.

## Drawback 
On failure, however, all that state needs to be recovered so that the filesystem remains consistent. This requires that the state must be incrementally check-pointed to prevent too much loss. In addition, there are runtime overheads incurred by the server to maintain state and enforce consistency protocols and by the client to perform caching.