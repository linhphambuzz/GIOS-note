![[Pasted image 20240926124205.png]]


- Flash is an event-driven web server that follows the AMPED model, which means it has asymmetric helper processes to help with blocking I/O operations.
- The blocking I/O operations that are happening in this scenario are basically just disk reads.
- The communication from the helpers to the event dispatcher is performed via pipes. 
- The helper reads the file in memory via `mmap` and then the dispatcher checks via `mincore` to see if the pages are in memory, and uses this information to determine if it should call a local handler or a helper. 
- As long as the file is in memory, reading it will not result in the blocking I/O operation, which means that the local handler can be used.

## Optimization

![[Pasted image 20240926125018.png]]
- Flash performs application level caching at multiple levels.
- It does this on both data and computation. It is common to cache files: this is data caching. Computation can also be cached. For instance, every request has an associated pathname, and we need to look up the file given the pathname. That lookup will compute some result, which we can cache so we do not have to perform the same computation again.
- Similarly, the fields in the HTTP header are often file dependent. So long as the file doesn't change, the headers don't need to change. Thus we can cache the response header so long as we can tell that the file hasn't changed. Again, we don't need to perform an unnecessary computation.

- Flash also makes some optimizations that take advantage of the available network hardware: fields doesn't need to be next to each other to be found, can be vectorized, scatter-datter support (i.e: header and file doesn't need to be next to each other)