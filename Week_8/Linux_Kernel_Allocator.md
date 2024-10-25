## Buddy allocator
![[Pasted image 20241019033636.png]]
- starts with some consecutive memory region that is free that is a power of two. 
- Whenever a request comes in, the allocator subdivides the area into smaller chunks such that every one of them is also a power of two. 
- It will continue subdividing until it finds a small enough chunk that is power of two that can satisfy the request.

### Example 
- First, a request for 8 units comes in. The allocator divides the 64 unit chunk into two chunks of 32. One chunk of 32 becomes 2 chunks of 16, and one of those chunks becomes two chunks of 8. We can fill our first request. Suppose a request for 8 more units comes in. We have another free chunk of 8 units from splitting 16, so we can fill our second request. Suppose a request for 4 units comes in. We now have to subdivide our other chunk of 16 units into two chunks of 8, and we subdivide one of the chunks of 8 into two chunks of 4. At this point we can fill our third request.

- When we release one chunk of 8 units, we have a little bit of fragmentation, but once we release the other chunk of 8 units, those two chunks are combined to make one free chunk of 16 units.

-> Fragmentation definitely still exists in the buddy allocator, but on free, one chunk can check with its "buddy" chunk (of the same size) to see if it is also free, at which point the two will aggregate into a larger chunk.


- This buddy checking step can continue up the tree, aggregating as much as possible. For example, imagine requesting 1 memory unit above, and then freeing it. We would have to subdivide the chunks all the way down to 1, but then could build them all the way back up to 64 on free.

- The reason that the chunks are powers of two is so that the addresses of budding only differs by one bit. For example, if my buddy and I are both 4 units long, and my starting address is 0x000, my buddy's starting address will be 0x100. This helps make computation easier.
Because the buddy allocator has granularity of powers of two, there will be some internal fragmentation using the buddy allocator. This is a problem because there are a lot of data structures in the Linux kernel that are not close to powers of 2 in size. For example, the task struct used to represent processes/threads is 1.7Kb.


## Slab Allocator 

- The slab allocator builds custom object caches on top of slabs. 
- The slabs themselves represent contiguously allocated physical memory.
![[Pasted image 20241019064643.png]]
- When the kernel starts it will pre-create caches for different objects, like the task struct. Then, when an allocation request occurs, it will go straight to the cache and it will use one of the elements in the cache. 
- If none of the entries is available, the kernel will allocate another slab, and it will pre-allocate another portion of contiguous memory to be managed by the slab allocator.
- The benefit of the slab allocator is that internal fragmentation is avoided. The entities being allocated in the slab are the exact size of the objects being stored in them. External fragmentation isn't really an issue either. Since each entry can store an object of a given size, and only objects of a given size will be stored, there will never be any un-fillable gaps in the slab.
