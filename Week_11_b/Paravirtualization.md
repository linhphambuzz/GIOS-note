Another approach gives up on unmodified guests, instead focusing on performance. In contrast to full virtualization, this is called **paravirtualization**.
- In paravirtualization, the guest now knows that it is running in virtualized environment on top of a hypervisor as opposed native physical resources.
- ![[Pasted image 20241113120525.png]] 
## Hypercall 
- A paravirtualized guest OS may not directly try to perform operations that it knows will fail, but will instead make explicit calls to the hypervisor to achieve the desired behavior. These calls are called **hypercalls** and they behave similar to system calls. The hypercall will trap to the hypervisor which, upon performing the required operation with the data supplied by the guest, will pass control back to the guest.

This approach was taken by Xen.

## QUiz 

![[Pasted image 20241113120828.png]]


