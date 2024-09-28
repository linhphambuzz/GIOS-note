A process is described by its process control block, which contains:

- virtual address mapping
- stack
- registers
## User-level thread

If the process links in a user level threading library, that library will need some way to represent threads, so that it can track thread resource use and make decisions about thread scheduling and synchronization.

The library will maintain some user level thread data structure containing:

- thread ids
- thread registers
- thread stacks

## Kernel-level thread 

If we want there to be multiple kernel level threads associated with this process, we don't want to have to replicate the entire process control block in each kernel level thread we have access to.

The solution is to split the process control block into smaller structures. Namely, the stack and registers are broken out (since these will be different for different kernel level threads) and only these pieces  of information are stored in the kernel level thread data structure.

![[Pasted image 20240917113532.png]]