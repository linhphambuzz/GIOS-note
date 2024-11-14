
## Approach 
![[Pasted image 20241113140734.png]]
- In the **split device driver model**, all of the devices accesses are controlled in a way that involves a component that resides in a guest VM and a component that resides in a hypervisor layer.
- The **front-end driver** resides in the guest VM and the actual driver for the physical device - the **back-end driver** - resides in the service VM (or the host in type 2 virtualization).
- Although the back-end driver doesn't necessarily have to be modified, as it is the same driver that the OS would use as if it were running natively, the front-end driver does need to be modified.

- The front-end driver needs to take the device operations that are made by the applications in the guest, and then wrap them in a standard format to be delivered to the back-end component. Because of this modification, this model can only really be used in paravirtualized guests.

## Benefit

One benefit of this approach is that the device emulation overhead can be eliminated. Another benefit of this approach is that the centralized back-end component allows for better management of shared devices.

