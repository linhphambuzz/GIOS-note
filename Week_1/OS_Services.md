![[Pasted image 20240822095538.png]]
## linked to hardware
- Scheduler: controlling the access to the CPU (**direct link to hardware components)**
- memory manager: allocating the underlying physical memorry to core **(direct link to hardware components)** application, ensure applications dont step on each other 
- block device driver: blocked device like disk **(direct link to hardware components)**

## Abstraction not directly linked to hareware

 exposing level abstractions as opposed to those that are linked with abstractions that are mapped to the hardware
- process management
- file management :supported by all os. principle OS integrate file system as a service  
- device management
- memory, storage, security.. 


## [System calls](./SYSTEM_CALL)

OS makes all svc avail via system calls 
![[Pasted image 20240822100216.png]]