
- The size of the memory page, or frame, is determined by the number of bits in the offset. For example, if we have a 10-bit offset, our page size is 2^10 bytes, or 1KB. A 12-bit offset means we have a page size of 4KB.\
- the offset determines what is the total amt of adresses in the page, and therefore determine the page size 
## Linux
In practice, systems support different page sizes. For Linux, on x86 platforms there are several common page sizes. 4KB pages are pretty popular, and are the default in the Linux environment. Page sizes can be much larger.

![[Pasted image 20241017224847.png]]

## Larger page 
![[Pasted image 20241017225105.png]]
- Larger pages means fewer page table entries, smaller page tables, and more TLB hits.
- Different system/hardware combinations may support different page sizes. For example, Solaris 10 on SPARC machines supports 8KB, 4MB, and 2GB.
