- one of the roles of the operating system is to manage the physical resources - in this case DRAM - on behalf of one or more executing processes.
- The operating system provides an address space to an executing process as a way from decoupling the physical memory from the memory that a process interacts with. Almost everything uses virtual addresses, and the operating system translates these address into physical addresses where the actual data is stored.
- The range of the virtual addresses that are visible to a process can be much larger than the actual amount of physical memory
## Allocate 

-  requires that the operating system incorporate certain mechanisms and data structures so that it can track how memory is used and what memory is free.
- In addition, since the physical memory is smaller than the virtual memory, it is possible that some of the virtual memory locations are not present in physical memory and may reference some secondary storage, like disk. The operating system must be able to replace the contents in physical memory with contents from disk.
## Arbitrate 
- requires that the operating system can quickly interpret and verify a process memory access.
- The OS should quickly be able to translate a virtual address into a physical address and validate it to verify that it is a legal access. Modern operating systems rely on a combination of hardware support and software implementations to accomplish this.


The virtual address space is subdivided into fixed-size segments called **pages**. The physical memory is divided into **page frames** of the same size.
- In terms of allocation, the operating system maps pages into page frames. In this type of **page-based memory management** the arbitration is done via **page tables**.
- Another approach is **segmentation**, or a **segment-based memory approach**. With segmentation, the allocation process doesn't use fixed-size pages, but rather more flexibly-sized segments that can be mapped to some regions in physical memory as well as swapped in and out of physical memory. Arbitration of accesses uses **segment registers** that are typical supported on modern hardware.
![[Pasted image 20241016031355.png]]


## Hardware support
- Memory management is not done by the operating system alone. Hardware mechanisms help make memory management decisions easier, faster and more reliable.

### Memory Management Unit 
- Every CPU package contains a **memory management unit** (MMU). The CPU issues virtual addresses to the MMU, and the MMU is responsible for converting these into physical addresses.
### Faults 
- If there is an issue, the MMU can generate a **fault**. A fault can signal that the memory access is illegal; that is, there is an attempt to access memory that hasn't been allocated. A fault could also signal that there are insufficient permissions to perform a particular access. A third type of fault can indicate that the requested page is not present in memory and must be fetched from disk.

### Register 

- Another way that hardware supports memory management is by assigning designated registers to help with the memory translation process.
-  For instance, registers can point to the currently active page table in a page-based memory system. In a segmentation system, the registers may point to the base address, the size of the segment and the total numbers of segments.
- Since the memory address translation happens on every memory reference, most MMU incorporate a small cache of virtual/physical address translations. This is a called the **translation lookaside buffer** (TLB). This buffer makes the entire translation process a lot faster-> no additional operations needed to interpret the translation or the validity of the access 


### Translation 

- Finally, the actual translation of the physical address from the virtual address is done by the hardware. While the operating system maintains page tables which are necessary for the translation process; however, the actual hardware performs it.
- This implies that the hardware dictates what type of memory management modes are available, be they page-based or segment-based.
- It implies what kind of pages can there be, virtual and physical addr format
- allocation: which which on main/disk, software mgment
- replacement : which on main/disk, software mgment 

![[Pasted image 20241016032526.png]]

