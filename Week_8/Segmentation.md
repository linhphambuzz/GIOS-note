## Segment 
- Virtual to physical memory mappings can also be maintained using **segments**. 
- With segments, the address space is divided into components of arbitrary size, and the components will correspond to some logically meaningful section of the address space, like the code, heap, data or stack.
-
- A virtual address in the segmented memory mode includes a **segment selector** and an offset. The selector is used in combination with a **descriptor table** to produce a physical address which is combined with the offset to describe a precise memory location.
## Pure form 
- In its pure form, a segment could be represented with a contiguous section of physical memory. In that case, the segment would be defined by its base address and its **limit registers** (i.e: segment size). we can have segment with different size using this method 
## Segment + Pages
- In practice, segmentation and paging are used together. The linear address that is produced from the logical address by the segmentation process is then passed to the paging unit to ultimately produce the physical address.

## Addr translation 
- The type of address translation that is possible on a particular platform is determined by the hardware. Intel x86_32 platforms support segmentation and paging.
- Linux supports up to 8K segments per process and another 8K global segments. 
- Intel x86_64 platforms support segmentation for backward compatibility, but the default mode is to use just paging.
