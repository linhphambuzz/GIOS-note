- Remember that a page table has a number of entries that is equal to the number of virtual page numbers that exist in a virtual address space. If we want to calculate the size of a page table we need to know both the size of a page table entry, and the number of entries contained in a page table.
- On a 32-bit architecture, where each memory address is represented by 32 bits, each of the page table entries is 4 bytes (32 bits) in size, and this includes both the PFN and the flags. The total number of page table entries depends on the total number of VPNs.
- In a 32-bit architecture we have 2^32 bytes (4GB) of addressable memory. A common page size is 4KB. In order to represent 4GB of memory in 4KB pages, we need 2^32 / 2^12 = 2^20 entries in our page table. Since each entry is 4 bytes long, we need 2^22 bytes of memory (4MB) to represent our page table.

- If we had a 64-bit architecture, we would need to represent 2^64 bytes of physical memory in chunks of 2^12 bytes. Since each entry is now 8 bytes long, we need 2^3 * 2^64 / 2^12 = 32PB!
Remember that page tables are a _per-process_ allocation.

It is important to know that a process will not use all of the theoretically available virtual memory. Even on 32-bit architectures, not all of the 4GB is used by every type of process. The problem is that the page table assumes that there is an entry for every VPN, regardless of whether the VPN is needed by the process or not. This is unnecessarily large.

