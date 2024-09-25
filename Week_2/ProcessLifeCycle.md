# States

![[Pasted image 20240826150945.png]]

- When a process is created, it is in the _new_ state. This is when the OS performs admission control, and allocates/initializes the PCB for this process
- At this point, the process moves to the _ready_ state, where it is ready to start executing, but isn't currently executing.
-  When the scheduler schedules the process and it moves on to the CPU it is in the _running_ state.
- The process can be interrupted and a context switch can be performed. This moves the process back to the _ready_ state.
- the running process may need to perform some I/O operation or wait on an event, at which point the process enters a _waiting_ state. The process can then move back to _ready_ when the I/O operation completes or the event occurs.
- Finally, a process can exit, with or without error when it finishes with all operations, and at this point the process is _terminated_.

# Creation

In operating systems, a process can create one or more _child processes_. The creating process is the parent and the created process is the child. All of the processes that are currently loaded will exist in a tree-like hierarchy.

Once the operating system is done booting, it will create some _root_ processes. The processes have privileged access.

- On unix-based OS, `init` is the base of all processes 

![[Pasted image 20240826164405.png]]

### Fork 

- The operating system will create a new PCB for the child, and then will copy the exact same values from the parent PCB into the child PCB. 
- The result is that both processes will continue executing with the exact same state at the instruction immediately following the fork (they have the same program counter).

### Exec 
- the operating system will take a PCB (created via fork), but will not leave the values to match those of the parents. 
- Instead operating system loads a new program, and the child's PCB will now point to values that describe this new program. 
- The program counter of the child will now point to the first instruction of the new program.
-> For "creating" a new program, you have to call fork to get a new process, and then call exec to load that program's information into the child's PCB.
