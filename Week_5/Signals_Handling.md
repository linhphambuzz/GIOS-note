![[Pasted image 20240921113842.png]]
- Signals are different from interrupts in that signals originate from the CPU. For example, if a process tries to access memory that has not been allocated, the operating system will generate a signal called SIGSEGV.
- For each process, the OS maintains a mapping where the keys correspond to the signal number (SIGSEGV is signal 11, for example), and the values point to the starting address of handling routines. When a signal is generated, the program counter is adjusted to point to the handling routine for that signal for that process.
- The process may specify how a signal can be handled, or the operating system default may be used. Some default signal responses include:

	- Terminate
	- Ignore
	- Terminate and Core Dump
	- Stop
	- Continue (from stopped)

For most signals, processes can install its custom handling routine, usually through a system call like `signal` or `sigaction` although there are some signals which cannot be caught which would always kill the process. 

![[Pasted image 20240921114218.png]]

## Synchronous
Some synchronous signals include:

- SIGSEGV: attempted to access protected memory
- SIGFPE (divide by zero)
- SIGKILL (kill, id from one process to another)

## Asynchronous signal 

Some asynchronous signals include:

- SIGKILL (as the receiver)
- SIGALARM (timeout from timer expiration)
