How virtualization technique can be developed that achieved our goal to efficiently at near native speeds allow execution of virtual machines  on top of identical hardware platforms.

## Guest instructions : non privileged 

- Guest instructions are executed directly by the hardware. The VMM does not interfere with every instruction that is issued by the guest OS or its applications.
- As long as the guest OS is operating within the resources allocated to it by the hypervisor, the instructions will operate at hardware speeds, which will underline the efficiency of the virtualization solution.

## Guest instructions : privileged
- Whenever a privileged instruction is issued, the processor causes a trap to the hypervisor
- . At this point, the hypervisor can determine if the operation is to be allowed or not. If the operation is illegal, the hypervisor can perform some punitive action, like shutting down the VM. 
- If the operation should be allowed, the hypervisor must provide the necessary emulation to ensure that the guest OS receives the response it was expecting from the hardware. This is known as the **trap-and-emulate** strategy -> achieve efficeency in virtualization
![[Pasted image 20241109105830.png]]
The hypervisor intervention must be invisible to the guest OS.

