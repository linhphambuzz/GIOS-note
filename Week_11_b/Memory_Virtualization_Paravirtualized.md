![[Pasted image 20241113123334.png]]
## Paravirtualized 
- Since an OS knows that it is in a virtualized environment in paravirtualization, it is no longer a strict requirement that the guest OS uses contiguous physical memory starting at 0.

- The guest OS can explicitly register its page tables with the hypervisor, so there is no need for two page tables.

- The guest still doesn't have write permissions to this page table - which is now used directly by the hardware - as this would allow as guest to potentially corrupt another guest by overwriting its memory.

## Optimization 
Because of this, every write to the page table will cause a trap to the hypervisor. However, since the guest is paravirtualized, we can modify the guest to batch page table updates into a single hypercall, amortizing the cost of the VM exit across multiple updates.

Many of the overheads associated with memory virtualization in both full and paravirtualization have been reduced by improvements on newer hardware platforms.

