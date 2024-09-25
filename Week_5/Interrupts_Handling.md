![[Pasted image 20240921113407.png]]

- When a device wants to send a notification to the CPU, it sends an interrupt by sending a signal through the interconnect that connects the device to the CPU.

- Most modern devices use a special message, **MSI** that can be carried on the same interconnect that connects the device to the CPU complex. Based on the pins on where the interrupt is received or the message itself, the interrupt can be uniquely identified.

- The interrupt interrupts the execution of the thread that was executing on top of the CPU, so now what? The CPU looks up the interrupt number in a table and executes the handler routine that the interrupt maps to. The interrupt number maps to the starting address of the handling routine, and the program counter can be set to point to that address to start hazndling the interrupt.

All of this happens within the context of the thread that is interrupted.

Which interrupts can occur depends on the _hardware_ of the platform and how the interrupts are handled depends on the _operating system_ running on the platform.