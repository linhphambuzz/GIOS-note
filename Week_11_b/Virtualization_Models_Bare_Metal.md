## Bare metal 
![[Pasted image 20241105152812.png]]
- In **bare-metal** virtualization (also known as **hypervisor-based** or **type 1** virtualization, the VMM manages all the hardware resources and support execution of VMs.
- One issue with this model concerns devices. According to the model, the hypervisor must manage all possible devices. In other words, device manufacturers now have to provide device drivers not just for different operating systems, but also for different hypervisors.
- To eliminate this problem, the hypervisor model typical integrates a special virtual machine, a service VM, that runs a standardized OS with full hardware access privileges, allowing it to manipulate hardware as if it were native.
- The privileged VM runs all of the device drivers and controls how the devices on the platform are used. This VM will run some other configuration and management tasks to further assist the hypervisor.
- This model is adapted by the **Xen** virtualization software and by the **ESX** hypervisor from VMware.

![[Pasted image 20241105153928.png]]

Regarding Xen, the VMs that run in the virtualized environment are referred to as domains. The privileged domain is referred to as **dom0** and the guest domains are referred to as **domUs**. Xen is the hypervisor. All of the device drivers are running in dom0.

VMware maintains the largest share of server cores. VMware has been able to mandate that device manufactures develop drivers that can be used by the hypervisor. Since VMware targets servers, there are relatively few devices. To support the open source community, VMware has many open source APIs.

VMware used to have a control core based in Linux (similar to the dom0 in Xen), but now all of the configuration is done via remote APIs.

