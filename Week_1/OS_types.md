## Monollithic

![[Pasted image 20240823072904.png]]
- Anyone of the applications that're required or any part of the hardware is already part of the OS
- FS for sequential, for randomizing 
- Cons: makes OS large, customization, portability, performance, memory foot print
- Pros: everything is included, compile time optimisation 
## Modular OS 

- Basic services are already part of it, everything can be added as a module 
- Customize FS or Scheduler the OS uses -> module 
![[Pasted image 20240823073526.png]]
- OS specifies certain interface that any module must implement in order to be part of the OS 
- Example: for database application, they might run the file system that's optimized for random file access. If they're other types of applications, they might run the file for sequential access 
![[Pasted image 20240823074031.png]]
- It doesn't impact performance a whole lot
- everything has to go thru module interface 
- this is deliver significant improvement over monolithic approach 