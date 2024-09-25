The scheduler dictates how processes can access hardware platform and this includes IO 

- When a process makes an I/O request, the operating system will deliver that request -> move the process to the **I/O queue** for that particular I/O device
- The process will remain in the queue until the request is responded to
- after which the process will move back to a ready state  , or might immediately be scheduled on the CPU depends on how busy it is


Processes can end up on the ready queue in a few ways.
![[Pasted image 20240826175654.png]]