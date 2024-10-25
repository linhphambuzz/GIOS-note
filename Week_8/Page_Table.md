- Page tables are used to convert the virtual memory addresses into physical memory addresses.

- For each virtual address, an entry in the page table is used to determine the actual physical address associated with that virtual address. To this end, the page table serves as a map, mapping virtual addresses to physical addresses.
- The sizes of the pages in virtual memory is identical to the sizes of the page frames in physical memory. By keeping the size of these the same, the operating system does not need to manage the translation of every single virtual address within a page. Instead, we can only translate the first virtual address in a page to the first physical address in a page frame. The rest of the memory address in the page map to the corresponding offsets in the page frame. As a result, we can reduce the number of entries we have in the page table.
## virtual page number
- What this means is that only the first portion of the virtual address is used to index into the page table. We call this part of the address the **virtual page number** (VPN), and the rest of the of the virtual address is the **offset**
- The VPN is used as an index into the page table, which will produce the **physical frame number** (PFN), which is the first physical address of the frame in DRAM.
- o complete the full translation, the PFN needs to be summed with the offset specified in the latter portion of the virtual address to produce the actual physical address.
- The PFN with the offset can be used to reference a specific location in DRAM.

![[Pasted image 20241016045050.png]]

## Example 

- Let's say we want to initialize an array for the very first time. We have already allocated the memory for that array into the virtual address space for the process, we have just never accessed it before. Since this portion of the address space has not been accessed before, the operating system has not yet allocated memory for it.
- What will happen the first time we access this memory is that the operating system will realize that there isn't physical memory that corresponds to this range of virtual memory addresses, so it will take a free page of physical memory, and create a page table entry linking the two.
### Allocation on first touch
- The physical memory is only allocated when the process is trying to access it. This is called **allocation on first touch**.
- The reason for this is to make sure that physical memory is only allocated when it's really needed. Sometimes, programmers may create data structures that they don't really use.
### Bits in Page tables
- If a process hasn't used some of its memory pages for a long time, it is possible that those pages will be reclaimed. The contents will no longer be present in physical memory. They will be swapped out to disk, and some other content will end up in the corresponding physical memory slot.
- In order to detect this, page table entries also have a number of bits that give the memory management system some more information about the validity of the access.
- For instance, if the page is in memory and the mapping is valid, its valid bit will be 1. Otherwise, it will be 0.
- If the MMU sees that this bit is 0 when an access is occurring, it will raise a fault and trap to the operating system. The OS has to decide if the access should permitted, and if so, where the page is located and where it should be brought into DRAM.
- Ultimately, if the access is granted, there will be a new page mapping that is reestablished after access is granted. This is because it is unlikely the physical address will exist at the exact same PFN + offset as before. (i.e: before the PFN is p2 now p3)

![[Pasted image 20241016050317.png]]

## Summary
![[Pasted image 20241016050526.png]]
In summary, the operating system creates a page table for every single process in the system. That means that whenever a context switch is performed, the operating system must swap in the page table associated with the new process. Hardware assists with page table access by maintaining a register that points to the active page table. On x86 platforms, this register is the **CR3 register**.