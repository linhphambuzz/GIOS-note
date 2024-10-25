- Since the physical memory is much smaller than the addressable virtual memory, allocated pages don't always have to present in physical memory. Instead, the backing physical page frame can be repeatedly saved and stored to and from some secondary storage, like disk.

- This process is knowing as **paging** or **demand paging**. In this process, pages are **swapped** from DRAM to a secondary storage device like a disk, where the reside on a special swap partition.

![[Pasted image 20241019064929.png]]


## Procedure 
1. When a page is not present in memory, it has its present bit in the paging table entry set to 0. 
2. When there is a reference to that page, then the MMU will raise an exception - a page fault - and that will cause a trap into the kernel.
3. It can determine that it has previously swapped out this memory page onto disk. It can establish what's the correct access that needs to be performed. It will then issue an IO operation to retrieve this page 
4. Once the page is brought into memory, he OS will determine a free frame where this page can be placed, and it will use the PFN to appropriately update the page table entry that corresponds to the virtual address for that page. 
5. At that point, control is handed back to the process that issued this reference, and the program counter of the process will be restarted with the same instruction, so that this reference will now be made again. This time, the reference will succeed.

Note that the original physical addr page might be different from the physical address page after it being swapped. 

## Pin
We may require a page to be constantly present in memory, or maintain its original physical address throughout its lifetime. We will have to **pin** the page. In order words, we disable swapping. This is useful when the CPU is interacting with devices that support direct memory access, and therefore don't pass through the MMU.

