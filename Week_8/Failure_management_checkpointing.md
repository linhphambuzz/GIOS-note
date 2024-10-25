## Checkpointing
- Checkpointing is a failure and recovery management technique.
-  The idea behind checkpointing is to periodically save process state. A process failure may be unavoidable, but with checkpointing, we can restart the process from a known, recent state instead of having to reinitialize it.
### Simple approach 

- A simple approach to checkpointing would be to pause the execution of the process and copy its entire state.
### Better approach 

- will take advantage of the hardware support for memory management and it will try to optimize the disruption that checkpointing will cause on the execution of the process.
- We can write-protect the process state and try to copy everything once.
- However, since the process continues executing, it will continue dirtying pages. We can track the dirty pages - again using MMU support - and we will copy only the diffs on the pages that have been modified. That will allow us to provide for incremental checkpoints.
- This incremental checkpointing will make the recovery of the process a little bit more challenging, as we have to rebuild the process state from multiple diffs.


### Debugging 

-  For instance, debugging often relies on a technique called **rewind-replay**.
- Rewind means that we will restart the execution of a process from some earlier checkpoint.
- We will then replay the execution from that checkpoint onwards to see if we can reproduce the error.
- We can gradually go back to older and older checkpoints until we find the error.


### Migration 

- With migration, we checkpoint the process to another machine, and then we restart it on that other machine. This is useful during disaster recovery, or during consolidation efforts when we try to condense computing into as few machines as possible.
- One way that we can implement migration is by repeating checkpoints in a fast loop until there are so few dirtied pages that a pause-and-copy becomes acceptable - or unavoidable.