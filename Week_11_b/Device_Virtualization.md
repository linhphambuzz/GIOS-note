
![[Pasted image 20241113131746.png]]

## CPU/Memory Virt. 
When we talk about CPU/Memory virtualization, certain things are relatively less complicated because there is a significant level of standardization at the **instruction set architecture** (ISA) level across different platforms.

From a virtualization standpoint, we know that we have to support a specific ISA and we don't care if there are lower level differences between the hardware because it is up to the hardware manufacturers to be standardized at the ISA level.

This is the case for a specific ISA like x86.

## Device Virt. 

When we look at devices, there is a much greater diversity in the type of devices. Also, there is a lack of standardization when it comes to the specifics of the device interface and the semantics of that interface.

To deal with this diversity, virtualization solutions adapt one of three key models to virtualize devices.