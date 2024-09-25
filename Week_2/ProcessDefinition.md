- Instance of an executing program 
- task /job = process

## Components 
1. State of execution: program counter, stack -> schedule, swap with multiple processes, management parts 
2. Parts : data, register state occupied state in memory 
3. require special hardware: IO devices (disk, network devices)
-> OS manages which processes are concurrently running and allow access to hardware 

## Process Definition

- operating system is to manage the hardware on behalf of **applications**. When an application is stored on disk, it is static.
- Once an application is launched, **it is loaded into memory and starts executing**; it becomes a **process**. A process is an active entity.
- ![[Pasted image 20240824153932.png]]

If the same program is launched more than once, multiple processes will be created. They will have the same instructions, but very different state.

-> **A process represents the active state of an application**
It may not be running at every given moment, but it is application that has been loaded and started.

## What does a process look like?

- A process encapsulates all of the state of a running application. This includes the code, the data, the heap, and the stack, all of what the application needs to allocate 
-  Every element of the process state has to be uniquely identified by its address.
- An operating system abstraction used to encapsulate all of the process state is an **address space**

### [Address Space](./ProcessAddressSpace)
- The address space is defined by a range of addresses V_0 to V_max. Different types of process state will appear in different regions of the address space.

### Types of States
1. Code/ text: The data available when process is first initialized (static state) 
2. Heap: Dynamically created state (what we create) , allocates memory, stores them per out results, read data from files. Seems contiguous with data but there are holes we may not allow to  access 
3. Stack: Dynamically created state that grows and shrinks as the program executes _LIFO_ Stack frames added and removed as functions are called and return
![[Pasted image 20240824155552.png]]