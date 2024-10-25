
![[Pasted image 20241009143159.png]]
- In shared memory IPC, processes read and write into a shared memory region. The operating system is involved in establishing the shared memory channel between the processes. 
- What this means is that the OS will map certain physical pages in memory into the virtual address spaces of both processes.
- The virtual addresses in each process pointing a shared physical location do not have to be the same. In addition, the shared physical memory section does not need to be contiguous.

## Pros 

The big benefit of this approach is that once the physical memory is mapped into both address spaces, the operating system is out of the way. System calls are used only in the setup phase.
![[Pasted image 20241009143525.png]]

## Cons
Since the shared memory area can be concurrently accessed by both processes, this means that processes must explicitly synchronize their shared memory operations. In addition, it is now the developer's responsibility to handle any protocol-related implementations, which adds to the complexity of the application.

## Data copies

Data copies are reduced, but not necessarily avoided. For data to be available to both processes, it needs to explicitly be allocated from the virtual addresses the belong to the shared memory region. If that is not the case, the data within the same address space needs to be copied in and out of the shared memory region.

Unix-based system support two popular shared memory APIs: SysV and POSIX. In addition, shared memory IPC can be established between processes by using a memory-mapped file Android ashmem...

