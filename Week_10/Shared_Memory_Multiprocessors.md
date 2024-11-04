
- A multiprocessor system consists of more than one CPU and some memory unit that is accessible to all of these CPUs. That is, the memory component is shared by the CPUs.
## Interconnect-based
- multiple memory references can be in flight at a given moment, one to each connected memory module
## Bus-based
- In a bus-based configuration, the shared bus can only support one memory reference at a time.
__________________________

- Because the memory are accessible to all CPUs -> these systems are called shared-memory processor. 
- Shared memory multiprocessors are also referred to as symmetric multiprocessors, or just SMPs. 
____________________

## Caching 
- Each of the CPUs in an SMP platform will have a cache.
- caches hide memory latency. This latency is even more pronounced in shared memory systems because there may be contention amongst different CPUs for the shared memory components. This contention will cause memory accesses to be delayed, making cached lookups appear that much faster.

## CPU performing write 

- For example, we may not even allow a CPU to write to its cache. A write will go directly to main memory, and any cache references will be invalidated. This is called **no-write**.
- As one alternative, the CPU write may be applied both to the cache and in memory. This is called **write-through**.
- A final alternative is to apply the write immediately to the cache, and perform the write in main memory at some later point in time, perhaps when the cache entry is evicted. This is called **write-back**.

