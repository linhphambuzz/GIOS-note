1. Page table dir 
- The outer level is referred to as a **page table directory**. Its elements are not pointers to individual page frames, but rather pointers to page tables themselves.
2. The internal page tables
- The inner level has proper page tables that actually to point to page frames in physical memory. Their entries have the page frame number and all the protection bits for the physical addresses that are represented by the corresponding virtual addresses.
- The internal page tables exist only for those virtual memory regions that are actually valid. Any holes in the virtual memory space will result in lack of internal page tables.
3. new memory request 
- If a process requests more memory to be allocated to it via `malloc` the OS will check and potentially create another page table for the process, adding a new entry in the page table directory. The new internal page table entry will correspond to some new virtual memory region that the process has requested.

----------------------------------
To find the right element in the page table structure, the virtual address is split into more components. 
![[Pasted image 20241017050657.png]]
- The last part of the logical address is still the offset, which is used to actually index into the physical page frame.
- The first two components of the address are used to index into the different levels of the page tables, and they ultimately will produce the PFN that is the starting address of the physical memory region being accessed. 
- The first portion indexes into the page table directory to get the page table, and the second portion indexes into the page table to get the PFN.

-----------------------------------------
![[Pasted image 20241017051036.png]]

- In this particular scenario, the address format is such that the outer index occupies 12 bits, the inner index occupies 10 bits, and the offset occupies 10 bits.
- This means that a given page table can contain 2^10 entries (p2), and each entry can address 2^10 bytes of physical memory (d). Loosely, we can think about the page table pointing to 2^10 "rows" of physical memory, with each row having 2^10 "cells". P2 gives us the memory "row", and d gives us the "cell" within that "row". This means that each page table can address 1MB of memory.
- Whenever there is a gap in virtual memory that is 1MB (or greater), we don't need to fill in the gap with (unused) page tables.
- For example, if we have a page table containing pages 0-999, and we allocate another page table containing pages 30000-30999, we don't need to allocate the 29 page tables in between.
- This will reduce the overall size of the page table(s) that are required for a particular process. This is in contrast to the "flat" page table, in which every entry needs to be able to translate every single virtual address and it has entries for every virtual page number. There can't be any gaps in a flat page table.

## Additional Layers
![[Pasted image 20241017051545.png]]
The hierarchical page table can be extended to use even more layers. We can have a third level that contains pointers to page table directories. We can add a fourth level, which would be a map of page table directory pointers.

This technique is important on 64-bit architectures. The page table requirements are larger in these architectures (think about how many bits can be allocated to p2 and d), and as a result are often more sparse (processes on 64-bit platforms don't necessarily need more memory than those on 32-bit platforms).
- Because of this, we have larger gaps between page tables that are actually allocated. With four level addressing structures, we may be able to save entire page table directories from being allocated as a result of these gaps.



## example
 ![[Pasted image 20241017051738.png]]
 - As we add more levels, the internal page tables/directories end up covering smaller regions of the virtual address space. As a result, it is more likely that the virtual address space will have gaps that will match that granularity, and we will be able to reduce the size of the page table as a result.

- The downside of adding more levels to the page table structure is that there are more memory accesses required for translation, since we will have to access more page table components before actually accessing the physical memory. Therefore, the translation latency will be increased.

