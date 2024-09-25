 ![[Pasted image 20240917112001.png]]


- Threads can be supported at the user level, the kernel level, or both.
## Kernel Level
Supporting threads at the kernel level means that the operating system itself is multithreaded. To do this the kernel must maintain some **data structure** to represent threads, and must also maintain all of the **scheduling and syncing mechanisms** to make multithreading correct and efficient.

## User Level
Supporting threads at the user level means there is a user level library linked with the application that provides all of the management and support for threads. It will support the **data structure** as well as the **scheduling mechanisms**. Different processes may use entirely different user level thread libraries.

## Mapping 
User level threads can be mapped onto kernel level threads via a 1:1, many:1 and many:many patterns.