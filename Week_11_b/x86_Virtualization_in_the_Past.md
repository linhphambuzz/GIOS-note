
## Problem 
Before 2005, x86 platforms had only the four privilege rings, without the root/non-root distinction. The basic strategy for virtualization software was to run the hypervisor in ring 0, and the guest operating system in ring 1.

However, there were exactly 17 hardware instructions that were privileged (required ring 0), but didn't cause a trap. Issuing them from another protection level wouldn't pass control to the hypervisor, but would just fail silently.
For example, enabling/disabling interrupts requires manipulating a bit in a privileged register, which can be done with the POPF/PUSHF instructions. When these instructions were issued, they just failed silently.


## [](https://www.omscs-notes.com/operating-systems/virtualization/#binary-translation)

![[Pasted image 20241109122513.png]]

Since control isn't passed to the hypervisor, the hypervisor has no idea that the OS wanted to change the interrupt status, so it cannot emulate that behavior.

At the same time, since the failure was silent, the OS doesn't know about it and assumes the change was successful. As a result, it continues with its execution.


## Quiz

![[Pasted image 20241113113851.png]]