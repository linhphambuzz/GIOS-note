## Virtual Adresses
- Potential range of addresses in process address space go from V_0 to V_max. These addresses are called **virtual addresses** that used by the process to reference some of its state. They are virtual because they don't have to correspond to actual locations in the physical memory.

## Page table 

- a page table: Memory management hardware and components of the operating system maintain a mapping between virtual memory addresses and physical memory addresses.
-> we can _decouple_ the layout of the data in the virtual address space from the layout of the data in physical memory. This also allows physical memory not being dictated by the layout of the virtual memory 
-  Example: data may live at `0x03c5` in the virtual address space and this may map to `0x0f0f` in physical memory. any request to access in virtual adress, process will have their data wo knowing its physical location


## Physical Memory vs. Disk access 

![[Pasted image 20240824163454.png]]

- In the scenario where we have to run  mulitple processes 
- In the pictures, some address region of P1 or P2 are swapped to disk, and might be brought in when needed
- OS maintains the mapping from virtual addresses  to physical memory (DRAM), and nd must also check the validity of memory accesses