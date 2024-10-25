 

![[Pasted image 20240822081617.png]]
## Privilege kernel mode 

- OS kernel priviledge direct hardware access 
- A special mode is set in the CPU  -> any instruction that directly manipulates hardware is permitted to execute
## Unprivileged /user mode 

- In this mode, the bit in the CPU is not set and any attempt to operation will be forbidden

### Trap instructions 
- Attempt to perform privilege operation on user map will cause a "trap". the app will be interrupted. 
- The hardware will switch the control to the OS at a certain location -> OS will try to determine if it should run the access or  terminate that access  if illegal 
## User- Kernel Switch
- is supported by hardware: trap instructions, system call 
- The interaction between application and OS can be via system call 
###  [System Call](./SYSTEM_CALL)
- The OS export a system call interface: a set of operations that the application can explicitly evoke if they want OS to perform things on their behlaf.
- Example : open(file), sned(socket), malloc(memory)

### Signals 
OS passes notification into the applications

## User/Kernel Transitions 
- hardware supported : traps on illegal instructions on memory access requireing special privilege. Application can't change the content of certain register & give itself more CPU, more memory only OS can  
- The result of the trap : 
    1.  hw initiates transfer of ctrl to OS -> to kernel 
    2. once marks this by the special privilege bit,  ctrl is passed to OS 
    3. Os determines determine whether grant or deny, depends on the policy 
- Involves a number of instructions :
   - e.g: 50 ~100 ns on a 2Ghz machine running Linux 
- Switches locality -> affect hardware cache 
- Not cheap 

### Note on context switch 

- Context switches will swap the data/addresses currently in **cache**, the performance of applications can benefit or suffer based on how a context switch changes what is in **cache** at the time they are accessing it
- A **cache** would be considered **hot** (fire) if an application is accessing the **cache** when it contains the data/addresses it needs 
- Likewise, a **cache** would be considered **cold** (ice) if an application is accessing the **cache** when it does not contain the data/addresses it needs -- forcing it to retrieve data/addresses from main memory 