## Linux

- Hardware (CPU, memory, disks, terminals) 
- Linux Kernel/OS (process management, memory management, FS, IO): abstract and manages hw by supporting a numbers of abstractions and the associated numbers of mechanisms 
- Standard Libraries  implements sys call interfaces 
- Standard Utility program (shells/compiler): usr to interact with the OS 
- User applications
![[Pasted image 20240823111513.png]]


**![[Pasted image 20240823111824.png]]**

Kernel consist of several logical components

- Virtual file system
- Memory management
- Process management

Each subcomponent within the three above can be modified or replaced 'cause modularity!


## MAC OS 
![[Pasted image 20240823112014.png]]

- I/O kit for device drivers
- Kernel extension kit for dynamic loading of kernel components
- Mach microkernel _memory management_ thread scheduling * IPC
- BSD component _Unix interoperability_ POSIX API support * Network I/O interface
- All applications sit above this layer