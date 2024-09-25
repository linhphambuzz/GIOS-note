- Microkernels only require the most basic operating system components.
- Everything else (including file systems and disk drivers) will run outside of the operating system at user-level.
- This setup requires lots of interprocess communication (IPC), as the traditional operating system components (i.e: FS, disk driver) run within application processes.
![[Pasted image 20240823110045.png]]

-> As a result, the microkernel often supports IPC as a core abstraction.

### Pros 
- Size
- Verifiability (great for embedded devices)
### Cons 

- Bad portability (often customized to underlying hardware)
- Harder to find common OS components due to specialized use case
- Expensive cost of frequent user/kernel crossing

