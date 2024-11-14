- A virtual machine is an **efficient, isolated duplicate** of a real machine.
- Virtualization is supported by the virtual machine monitor (VMM). The VMM has three responsibilities.
1. First, the VMM must provide an environment that is essentially identical to the original machine. The capacity may differ, but the overall setup (type of CPU, types of devices) should be the same. The VMM must provide some **fidelity** that the representation of the hardware that is visible to the VM matches the hardware that is available on the physical platform.
2. Second, programs that run in VMs must show at worst only minor decreases in speed. Clearly, the VMs are only given a portion of the resources available to the host machine. However, the goal of the VMM is to ensure that the VM would perform at the same speed as a native application if it were given all of the host's resources. The VMM must provide **performance** to the VMs that is as close to native performance as possible.
3. Finally, the VMM is in complete control of the system resources. The VMM controls who access which resources and when, and it can be relied upon to provide **safety and isolation** among the VMs.

