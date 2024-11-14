
So far, we've focused on how to virtualized the CPU. Let's look at other types of resources looking at the memory first. 



## Full virt. 
- For full virtualization, a key requirement is that the guest OS continues to observe a contiguous, linear address space that starts from address zero. This is what an operating system would see if it actually owned the physical memory.
- To achieve this, we need to distinguish among three types of addresses: virtual addresses, physical addresses, and machine addresses.
### virtual addresses 

Virtual addresses are used by the applications in the guest.

### physical addresses

 Physical addresses are used by the kernel of the guest

### machine addresses
Machine address correspond to the physical addresses on the underlying physical platform.
______________
# OPTION 1
### Pages mapping 
The guest OS makes mappings of virtual addresses to the physical addresses that it thinks it owns. Underneath, the hypervisor maintains a mapping of the physical addresses to the machine addresses. "Contiguous" physical addresses can map to discontiguous machine addresses. In effect, there are two page tables: one maintained by the guest OS, and one maintained by the hypervisor.

### Hardware 

At the hardware level, the MMU and TLB help with the address translation process and free us from having to implement these translations in software.

-> In this setup, the first address translation exists solely in software, and the second translation can potentially leverage hardware components.

This is too expensive since this will add overhead on every memory reference.
________
# OPTION 2 
## Shadow page table 


In the shadow page table, the hypervisor re-maps the virtual addresses to machine addresses, without considering the physical addresses.

### Hypervisor's duty 
- The hypervisor will clearly have to maintain consistency between these two pages tables. The hypervisor will have to make sure to invalidate the shadow page table on context switch.
- It will also have to make sure to write protect the page table in order to keep track of new mappings. The write protection is necessary to ensure that whenever the guest tries to establish new address mappings, it will trap into the hypervisor. During the trap, the hypervisor can update its shadow page table. this is transparent to the guest OS


![[Pasted image 20241113121819.png]]