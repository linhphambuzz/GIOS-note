## Non-cache coherent (NCC)

- What happens when multiple CPUs reference the same data?
- On some architectures this problem needs to be dealt with completely in software; otherwise, the caches will be incoherent. For instance, if one CPU writes a new version of `X` to its cache, the hardware will not update the value across the other CPU caches. These architectures are called **non-cache-coherent** (NCC) architectures.
## Cached Coherent (CC )
- On cache-coherent (CC) architectures, the hardware will take care of all of the necessary steps to ensure that the caches are coherent. If one CPU writes a new version of X to its cache, the hardware will step in and ensure that the value is updated across CPU caches.
![[Pasted image 20241102162214.png]]


## Write-Invalidate (WI)

- Hardware using the **write-invalidate** (WI) strategy will invalidate all cache entries of `X` once one CPU updates its copy of `X`. Future references to invalidated cache entries will have to pass through to main memory before being re-cached.
- With write-invalidate, we pose lower bandwidth requirements on the shared interconnect in the system. This is because we don't have to send the value of `X`, but rather just its address so it can be invalidated amongst the other caches. Once a cache invalidation occurs, subsequent changes to `X` won't require subsequent invalidations: a cache either has an entry for `X` or it doesn't.
- If `X` isn't needed on any of the other CPUs anytime soon, its possible to amortize the cost of the coherence traffic over multiple changes. `X` can change multiple times on one CPU before its value is needed on another CPU.
## Write-Update (WU)

- Hardware using the **write-update** (WU) strategy will ensure that all cache entries of `X` are updated once one CPU updates its copy of `X`. Subsequent accesses of `X` by any of the CPUs will continue to be served by the cache.
- For write-update architectures, the benefit is that the `X` will be available immediately on the other CPUs that need to access it. We will not have to pay the cost of a main memory access. Programs that will need to access the new value of`X` immediately on another CPU will benefit from this design.
_______________
The use of write-update or write-invalidate is determined by the hardware supporting your platform. You as the software developer have no say in which strategy is used.

