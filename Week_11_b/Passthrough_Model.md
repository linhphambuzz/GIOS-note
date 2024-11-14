
## Approach  
- In the **passthrough model**, the VMM-level driver is responsible for configuring the access permissions to a device. 
- For example, it will allow a guest VM to have access to the memory where the control registers for the devices are mapped.

## Pros
- In this approach, the guest VM has exclusive access to a device. In addition, the VM can directly access the device, without interacting with the VMM. This model is also called the **VMM-bypass model**.

## Cons 
- The problem with this exclusive access is that is making sharing devices across VMs difficult. The hypervisor will need to continuously reassign who the device belongs to over time, and device access will not happen concurrently across VMs. This is often unfeasible.
- Because the hypervisor is completely out of the way, the guest VM and the device driver in the guest VM directly operate on and control the device. This means that there needs to be a device of the _exact same type_ on the physical platform that the guest OS expects.

![[Pasted image 20241113132611.png]]

One of the benefits of virtualization is that the guest VMs are decoupled from the physical hardware, which makes migration of guests across physical nodes easy.

This passthrough model breaks that decoupling as it binds a device to a VM. This reintroduces migration complexity as there may be some device specific/resident state that would need to be properly copied and configured to a destination mode.

