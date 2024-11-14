![[Pasted image 20241105142207.png]]

## Definition 
- In order to concurrently run diverse workloads on the same physical hardware without requiring that a single operating system be used for all of the applications, it was necessary to come up with a model where multiple operating systems can concurrently be deployed on the same hardware platform.

## Properties
- With virtualization, each of the operating systems that are deployed on the same physical platform has the illusion that it actually owns the underlying hardware resources, all or in part.

## VM 

- Each operating system, plus its applications and its virtual resources is called a **virtual machine** (VM). 
- VMs are sometimes referred to as _guests_ or _domains_.

## Virt. layer
- Supporting the coexistence of multiple VMs on a single physical machine requires underlying functionality in order to deal with the allocation and management of the real hardware resources. In addition, it is necessary to provide some isolation guarantees across VMs.
- This functionality is provided by the **virtualization layer**, also referred to as a **virtual machine monitor** or **hypervisor**.

## Quiz 

![[Pasted image 20241109103028.png]]