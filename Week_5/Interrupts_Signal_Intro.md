## Interrupts

- Interrupts are events that are generated **externally** by components other than the CPU to which the interrupt is delivered. Interrupts are notifications that some external event has occurred.
- Components that may deliver interrupts can include:

1. I/O devices
2. Timers
3. Other CPUs

- Which particular interrupts can occur on a given physical platform depends on the configuration of that platform, the types of devices the platform comes with, and the hardware architecture of the platform itself.

- Interrupts appear **asynchronously**. That is, they do not appear in response to any specific action that is taking place on the CPU.

## Signals
- Signals are events that are triggered by the CPU and the software running on it.
- Which signals can occur on a given platform depends very much on the given operating system. Two identical platforms will have the same interrupts but will have different signals if they are running different operating systems.
- Signals can appear both synchronous(i.e: allocate memory that's allocated before) and asynchronously. Signals can occur in direct response to an action taken by a CPU, or they can manifest similar to interrupts.


![[Pasted image 20240920154633.png]]

## Signals & Interrupts similarity 

![[Pasted image 20240920155408.png]]


![[Pasted image 20240921113103.png]]