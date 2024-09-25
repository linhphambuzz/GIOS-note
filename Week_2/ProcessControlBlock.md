## How does OS know what process is doing?

1. Source code is compiled ->binary is produced 
2. Binary is a sequence of instructions, not executed sequentially 
3. The CPU needs to know where in the bin. instruction the process currently is : this is done by the **program counter** 
4. There're other registers that are maintained by the CPU
5. Process stack is used to defined what a process is doing 
6. and a lot more 
### Program Counter 

 - is maintained in the CPU while the process is executing in the register 
 
### CPU registers 
- to hold values necessary during the execution with infomation about adresses for data, info about the execution seqeunce 

### Process stack 

- top of the stack is the stack ptr 


->To maintain all of this useful information for every single process, the operating system maintains a [**process control block**](ProcessControlBlock.md) or PCB.


## Process Control Block

- A process control block is a data structure that the operating system maintains for every process that it manages.
- Process control block contains:
	- process state
	- process number
	- program counter
	- CPU registers
	- memory limits
	- CPU scheduling info: when certain things need to be executed, priorities, etc. 
	- and more!
- 
- The PCB is created when the process is initially created, and is also initialized at that time. For example, the program counter will be set to point at the very first instruction.
- Certain fields of the PCB may be changed when process state changes. For example, virtual/physical memory mappings may be updated when the process requests more memory. This refelects the memory limits as well as the valid virtual addressn region for this process 
- The CPU maintains a register dedicated for the **program counter** for the currently executing process -> will get automatically updated by the CPU on every new instruction
- It is the job of the operating system to collect all of the data about a process - stored within CPU registers - and save it to the PCB when the process is no longer running

## How is a PCB used? 

- PCBs are stored in memory on behalf of a process by the operating system until it comes time for the process to start/resume execution. At that point, the process's PCB is loaded from memory into CPU registers, at which point instruction execution can begin. 
- CPU register will reflect the state of the current PCB
![[Pasted image 20240826145406.png]]\
Each time the operating system switches between processes, we call this a [context switch](./Context_Switch).