
- Operating systems rely on the MMU to perform address translation as well as access tracking and protection enforcement. The same hardware can be used to build other useful services beyond just these.
- One such mechanism is called **Copy-on-Write** (COW).
## During process creation 

- When we need to create a new process, we need to re-create the entire parent process by copying over its entire address space.
- However, many of the pages in the parent address space are static - they won't change - so it's unclear why we have to incur the copying cost.
- In order to avoid unnecessary copying, a new process's address space, entirely or in part, will just point to the address space of its parent. The same physical address may be referred to by two completely different virtual addresses belonging to the two processes. We have to make sure to **write protect** the page as a way to track accesses to it.
- If the page is only going to be read, we save memory and we also save on the CPU cycles we would waste performing the unnecessary copy
- If a write request is issued for the physical address via either one of the virtual addresses, the MMU will detect that the page is write protected and will issue a page fault.
- At this point, the operating system will finally create the copy of the memory page, and will update the page table of the faulting process to point to the newly allocated physical memory. Note that only the pages that need to be updated - only those pages that the process was attempting to write to - will be copied.
- Whether the write protection will be removed will depend on how many thing else it shares with, 

We call this mechanism copy-on-write because the copy cost will only be paid when a write request comes in.
- 

## [](https://www.omscs-notes.com/operating-systems/memory-management/#failure-management-checkpointing)