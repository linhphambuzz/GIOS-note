OS support a numbers of abstractions, and a numbers of mechanisms on top of these abstractions. 

### Abstractions

- Example: 
	- Process, Thread : corresponds to the applications that the OS executes
	- File, Socket, Memory Page : correspond to the hardware resources that the OS needs to manage. 

- Storage devices or network card for the socket are the actual memory 

### Mechanisms 
- Example: 
	- create (launch, execute), schedule -> to actually run on the CPU 
	- open, write, allocate 
### Policies
- Least- recently used (LRU), earlier deadline first (EDF)
- Max numbers of socket that a process have access to 
- Which data will be removed from physical memory (LRU)





