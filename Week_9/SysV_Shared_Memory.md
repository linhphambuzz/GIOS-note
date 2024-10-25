The operating systems supports **segments** of shared memory, which don't need to correspond to contiguous physical pages. 
The operating system treats shared memory as a shared resource using system wide policies.
That means that there is a limit on the total number of segments and the total size of the shared memory. Currently in Linux the limit is 4000 segments, although in the past it was as few as 6.

## Mechanism
- When a process requests that a shared memory segment is created, the operating system allocates the required amount of physical memory and then it assigns to it a unique key. 
- This key is used to uniquely identify the segment within the operating system. Another other process can refer to this segment using this key. If the creating process wants to communicate with other processes using this segment of shared memory, then it needs to make sure that they learn this key somehow.
 ![[Pasted image 20241009220719.png]]
 - Using the key, the shared memory segment can be attached by a process. This means that the operating system establishes a valid mapping between the virtual addresses of that process and the physical addresses that back the segment. Multiple processes can attach to the same shared memory segment. Reads and writes to these segments will be visible across all attached processes.
 - Detaching a segment means invalidating the virtual address mappings for the virtual address region that corresponded to that segment within that process. The page table entries for those virtual addresses will no longer be valid.

A segment is not really destroyed once it is detached. A segment may be attached, detached and re-attached by multiple processes many times through its lifetime.

Once a segment is created, it's essentially a persistent entity until there is an explicit request for it to be destroyed. Note that this is very different from memory that is local to a process, which is reclaimed when the process exits.


## SysV Shared Memory API 

![[Pasted image 20241009221034.png]]