![[Pasted image 20240822083743.png]]

# STEPS 
1. We're in the executing user process, whichs needs hardware access 
2. Users makes the system call, which is passed to the OS in privilege mode
3. The OS will perform the operation, execute system call involves: 
	 - changing the execution context from the user process to OS kernel 
	 - passing args, jumping somewhere the memory so that you can follow the instrcution int the system call 
	 - with the system call, control is passed to the OS operates in privilege mode 
4. once comples, os return the result
     - changing from kerner -> user mode
     - passing arg to the user's addr space 

### To make system call, application must 
1. Write arguments 
2. save relavant data at well-defined location 
3. make system call using defined code 
![[Pasted image 20240822084851.png]]


### Synchronous mode 

- The process will wait until the system call completes 