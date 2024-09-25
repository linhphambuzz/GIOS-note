
### Abstraction : memory page

- Corresponds to some addressable region of memory of some fixed size

### Mechanism: 
- integrates mechanisms to operate on the "page"
- allocate that "page" in DRAM 
- map the "page" into the address space of the process -> allow the process to access the physical memory for the content of that page
- Overtime, the page can be moved across physical memory 
### Policies 

Since it's faster to access data from memory than on disk -> policy decides data will be stored on disk or memory 
-  LRU over time will no longer be in physical memory -->  go to disk : swapping 