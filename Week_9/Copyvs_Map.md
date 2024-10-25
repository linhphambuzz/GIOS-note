
![[Pasted image 20241009212642.png]]
The goal of both message-based and memory-based IPC is to transfer data from the address space of one process to the address space of another process.
- In message-based IPC, this requires that the CPU is involved in copying the data, and CPU cycles are spent every time data is copied to/from ports.

- In memory-based IPC, CPU cycles are spent to map physical memory into the address spaces of the processes. The CPU may also be involved in copying the data into the shared address space, but note that there is no user/kernel switching in this case.
- The memory-mapping operation is costly, but it is a one time cost, and can pay off even if IPC is performed once. In particular, when we need to move large amounts of data from one address space to another address space, the time it takes to copy - via message-based IPC - greatly exceeds the setup cost of the setup mapping performed in memory-based IPC.
- Windows systems leverage this difference. If the data that needs to be transferred is smaller than a certain threshold, the data is copied in and out of a communication channel via a port-like interface. Otherwise the data is mapped into the address space of the target process. This mechanism is called **Local Procedure Calls** (LPC).

## [](https://www.omscs-notes.com/operating-systems/inter-process-communication/#sysv-shared-memory)