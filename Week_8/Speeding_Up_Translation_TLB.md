- Adding levels to our page table structure adds overhead to the address translation process.

- In the simple, single-level page table design, a memory reference requires two memory references: one to access the page table entry, and one to access the actual physical memory.
- In the four-level page table, we will need to perform four memory accesses to navigate through the page table entries before we can actually perform our physical memory reference. Obviously, this is slow!
## Page Table Cache 
- The standard technique to avoid these accesses to memory is to use a **page table cache**. On most architectures, the MMU integrates a hardware cache used for address translations.
- This cache is called the **translation lookaside buffer** (TLB). On each address translation, the TLB cache is first referenced, and if the results address can be generated from the lookup we can bypass all of the page table navigation. If we have a TLB miss, of course, we still need to perform the actual full lookup.
- In addition to the proper address translation, the TLB entries will contain all of the necessary protection/validity bits to ensure that the access is correct, and the MMU will generate a fault if needed.
- Even a small number of addresses cached in TLB can result in a high TLB hit rate because we usually have a high temporal and spatial locality in memory references.
- On modern x86 platforms, there is a 64-entry data TLB and 128-entry instruction TLB per core, as well as a shared 512-entry shared second-level TLB.

**![[Pasted image 20241017222126.png]]**