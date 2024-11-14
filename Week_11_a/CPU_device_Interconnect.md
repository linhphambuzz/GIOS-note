
Devices interface with the rest of the system via a controller that is typically integrated as part of the device packaging that is used to connect the device with the rest of the CPU complex via some CPU/device interconnect.

![[Pasted image 20241104112754.png]]
- In this figure, all of the the controllers are connected to the rest of the system via a **Peripheral Component Interconnect** (PCI) bus.
- Modern platforms typically support **PCI Express**, which is more technologically advanced than PCI-X and PCI. PCI Express has more bandwidth, is faster, has lower latency, and supports more devices than PCI-X. For compatibility reasons, though, most platforms will include PCI-X which follows the original PCI standard.
- The PCI bus is not the only possible interconnect that can be present in a system. In this example, we see a SCSI bus that connects SCSI disks and an expansion (peripheral) bus that connects things like keyboards.

The device controllers determine what type of interconnect a device can attach to. **Bridging controllers** can handle any difference between different types of interconnects.

