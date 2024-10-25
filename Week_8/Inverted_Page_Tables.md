## Inverted_Page_Tables 

- it is efficient to have a page table that is on the order of physical memory vs. the order of the virtual memory that a process can have 
- Inverted page tables are managed on a system-wide basis, not on a per-process basis, and each entry in the inverted page table points to a frame in main memory.
- The representation of a logical memory address when using inverted page tables is slightly different. The memory address contains the **process id** (PID) of the process attempting the memory address, as well as the virtual address and the offset.
- A linear scan of the inverted page table is performed when a process attempts to perform a memory access. When the correct entry is found - validated by the combination of the PID and the virtual address - it is the index of that entry that is the frame number in physical memory. That index combined with the offset serves to reference the exact physical address.
![[Pasted image 20241017222803.png]]
- Linear scans are slow, but thankfully, the TLB comes to the rescue to speed up lookups. That being said, we still have to perform these scans with some frequency, and we need a way to improve the performance.

## Hashing Page Table 

![[Pasted image 20241017222945.png]]
- Inverted page tables are often supplemented with **hashing page tables**. Basically, the address is hashed and looked up in a hash table, where the hash points to a (small) linked list of possible matches. This allows us to speed up the linear search to consider just a few possibilities.