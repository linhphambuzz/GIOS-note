 - PCB blocks corresponding to each process will reside in memory until the operating system loads that data into the CPU registers, at which point the process can begin executing instructions.
 - A _context switch_ is a mechanism used by the operating system to switch from the context of one process to the context of another process.

### Cost of context switching

### Direct Cost 
- the number of CPU cycles required to load and store a new PCB to and from memory
### Indirect Cost 
- process is running on the CPU a lot of its data is stored in the processor cache.
-  Accessing data from cache is _very_ fast (on the order of cycles) relative to accessing data from memory (on the order of hundreds of cycles).
- When the data we need is present in the cache, we say that the cache is _hot_. When a process gets swapped out, all of its data is cleared from the cache to leave space for data of another process's 
- The next time it is swapped in, the cache is _cold_. That is, the data is not in the cache and the CPU has to spend many more cycles fetching data from memory.
->Basically, we want to limit how often we context switch!

