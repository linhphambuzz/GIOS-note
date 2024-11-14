One way to solve the issue of the 17 hardware instructions was to write the VM binary to never issue those 17 instructions. This process is called **binary translation**.
## Goal 

- The goal pursued by binary translation is to run unmodified guest operating systems. We shouldn't need to install additional software or policies to alter the guest OS in order to run in a virtualized environment. When the guest OS is not modified, this type of virtualization is called **full virtualization**.
## Approach 



To avoid these bad hardware instructions, some interception and translation must take place at the virtualization layer. Instruction sequences - typically at a function-level granularity - that are about to be executed are captured from the VM binary. This needs to be done at runtime, dynamically, because the execution of the instruction sequences may depend on code passed in at runtime.
1. The first step involves capturing and inspecting code blocks that are about to be issued to see if any of the 17 hardware instructions are present.
2. If the code block does not have one of these instructions, the block is marked as safe and allowed to execute at hardware speeds. However, if one of the bad instructions is found, that instruction is translated into some alternate instruction sequence that still emulates the desired behavior.
3. Binary translation adds overheads! Mechanisms to reduce these overheads include caching translated code fragments and making sure to only analyze kernel code executed in the guest OS.

This approach was taken by VMware.

## [](https://www.omscs-notes.com/operating-systems/virtualization/#paravirtualization)
![[Pasted image 20241113115958.png]]