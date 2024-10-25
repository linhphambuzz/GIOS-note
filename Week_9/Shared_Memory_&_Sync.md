![[Pasted image 20241009221806.png]]
When data is placed in shared memory, it can be concurrently accessed by all processes that have access to that shared memory region. Therefore, such accesses must be synchronized in order to avoid race conditions. This is the same situation we encountered in multithreaded environments.


We can rely on the mechanisms supported by the threading libraries that can be used within processes. For example, two pthreads processes can synchronize amongst each other using pthreads mutexes and condition variables. In addition, the OS itself supports certain mechanisms for synchronization that are available for IPC.


Regardless of the method that is chosen, there must be mechanisms available to coordinate the number of concurrent accesses to shared segments (think mutexes) and to coordinate communicating when data is available or ready for consumption in the shared memory segment (think condition variables and signals).

## [](https://www.omscs-notes.com/operating-systems/inter-process-communication/#pthreads-sync-for-ipc)