
- Every page table entry will have at least a PFN and a valid bit. This bit is also called a present bit, as it represents whether or not the contents of the virtual memory are present in physical memory or not.
- There are number of other bits that are present in the page table entry which the operating system uses to make memory management decisions and also that the hardware understands and knows how to interpret.
1. dirty bit 
- For example, most hardware supports a **dirty bit** which gets set whenever a page is written to. This is useful in file systems, where files are cached in memory. We can use this dirty bit to see which files have been written to and thus which files need to be updated on disk.
2. acess bit 
- t's also useful to keep track of an **access bit**, which can tell us whether the page has been accessed period, for reads or for writes.
3. protection bit 
- We can also keep track of **protection bits** which specify whether a page is allowed to be read, written, or executed.
-

## Page table entry on x86

![[Pasted image 20241016051415.png]]


## Page fault 

- The MMU uses the page table entry not just to perform the address translation, but also to rely on these bits to determine the validity of the access.
- f the hardware determines that a physical memory access cannot be performed, it causes a page fault.
- If this happens, then the CPU will place an error code on the stack of the kernel, and it will generate a trap into the OS kernel,which will in turn invoke the **page fault handler**
- This handler determines the action to take based on the error code and the faulting address.
![[Pasted image 20241016051734.png]]

Pieces of information in the error code will include whether or not the page was not present and needs to be brought in from disk or perhaps there is some sort of permission protection that was violated and that is why the page access if forbidden.

On x86 platforms, the error code is generated from some of the flags in the page table entry and the faulting address is stored in the **CR2 register**.
