
An alternative to using PIO is to use **Direct Memory Access** (DMA) supported devices. This method requires additional hard support in the form of a DMA controller.
- For devices that have DMA support, the CPU still writes commands directly to the command registers on the device. However, the data movement is controlled by configuring the DMA controller to know which data needs to be moved from memory to the device, and vice versa.
- ![[Pasted image 20241104131804.png]]

## NIC controller 
- First, the CPU needs to write to a command register on the device. This command needs to instruct the device that it needs to perform a transmission of the data that the CPU will provide.
- This command needs to be accompanied with an operation that configures the DMA controller with the information about the memory address and size of the buffer that is holding the network packet. (locations and amt of data needed to be moved)
- If we have a 1500B packet that we wish to transmit using 8 byte data registers, the whole operation will take 1 CPU access to the command register and then 1 DMA configuration operation.
- DMA configuration is not a trivial operation! It takes many more cycles than a memory access. For smaller transfers, PIO will still be more efficient.

 *the data buffer must be in physical memory until the transfer completes. It cannot be swapped out to disk, since the DMA controller only has access to physical memory. This means that the memory regions involved in DMA are **pinned**. They are non-swappable.*
