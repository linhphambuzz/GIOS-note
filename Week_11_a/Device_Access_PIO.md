
![[Pasted image 20241104130917.png]]
- With just basic support from an interconnect like PCI, a CPU can request an operation from an I/O device using **programmed I/O** (PIO). This method requires no extra hardware support.
- The CPU issues instructions by writing into the command registers of the device. The CPU controls data movement to/from the device by reading/writing into the data registers for the device.

## NIC 
Let's consider how a process running on the CPU transmits a network packet via a **network interface card** (NIC) device.
- First, the CPU needs to write to a command register on the device. This command needs to instruct the device that it needs to perform a transmission of the data that the CPU will provide.
- The CPU then needs to copy the packet into the data registers, and will repeat as many times as necessary until the entire packet is sent.

For example, we may have a 1500B packet that we wish to transmit using 8 byte data registers. The whole operation will take 1 CPU access to the command register and then 188 - 1500 / 8 rounded up - accesses to the data register. In total, 189 CPU accesses are needed to transmit the packet.

## [](https://www.omscs-notes.com/operating-systems/io-management/#device-access-dma)