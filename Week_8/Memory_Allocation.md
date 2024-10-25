- Memory allocation incorporates mechanisms to decide what are the physical pages that will be allocated to a particular virtual memory region. Memory allocators can exist at the kernel level as well as at the user level.
## Kernel-lvl allocator 
- are responsible for allocating pages for the kernel and also for certain static state of processes when they are created - the code, the stack and so forth. In addition, the kernel level allocators are responsible for keeping track of the free memory that is available in the system.
## User-lvl allocator
- are used for dynamic process state - the heap.
- This is memory this is dynamically allocated during the process's execution. The basic interface for these allocators includes `malloc` and `free`. These calls request some amount of memory from kernel's free pages and then ultimately release it when they are done.
- Once the kernel allocates some memory through a `malloc` call, the kernel is no longer involved in the management of that memory. That memory is now under the purview of the user level allocator.



![[Pasted image 20241017233512.png]]

## Memory allocation challenges

![[Pasted image 20241019032914.png]]
- Consider a page-based memory management system that needs to manage 16 page frames. This system takes requests for 2 or 4 pages frames at a time and is currently facing one request for two page frames, and three requests for four page frames. The frames must be allocated contiguously for a given request.
- The operating system may choose to allocate the pages as follows: alloc(2), alloc(4),...
- Now suppose that the initial two request frames are freed. The page table may look like this now.
- What do we do when a request for four page frames comes in now? We do have four available page frames, but the allocator cannot satisfy this request because the pages are not contiguous.
## External fragmentation 
- This example illustrates a problem called **external fragmentation**. This occurs when we have noncontiguous holes of free memory, but requests for large contiguous blocks of memory cannot be satisfied.

## Alternative Strategy 
![[Pasted image 20241019033422.png]]
- Now when the free request comes in, the first two frames are again freed. However, because of the way that we have laid out our memory, we now have four _contiguous_ free frames. Now a new request for four pages can granted successfully.

- In summary, an allocator must allocate memory in such a way that it can coalesce free page frames when that memory is no longer in use in order to limit external fragmentation.

