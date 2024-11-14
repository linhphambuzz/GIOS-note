
![[Pasted image 20241105154234.png]]


The other type of virtualization model is the **hosted** (or **type 2**) model.

In this model, there is a full-fledged host OS that manages all of the hardware resources. The host OS integrates a VMM, which is responsible for providing the VMs with their virtual platform interface.

As necessary, the VMM module will invoke devices drivers and other host components as needed.

One benefit of this model is that it can leverage all of the services and mechanisms that are already developed for the host operating system. Much less functionality needs to be developed for the VMM module itself.

In this setup, you can run guest VMs through the VMM module as well as native applications directly on the host OS.
![[Pasted image 20241105154535.png]]
One example of the hosted model is **kernel-based VM** (KVM) which is built into Linux. The Linux host provides all aspects of the physical hardware management and can run regular Linux applications directly.

The support for running guest VMs comes from a combination of the KVM (VMM) module and a hardware emulator called **QEMU**.

QEMU is used in as a virtual interface between the VM and the physical hardware, and only intervenes during certain type of critical instructions; for example, I/O management.

KVM has been able to leverage all of the advances that have been contributed to the Linux open source community. Because of this KVM can quickly adapt to new features and fixes.

