
![[Pasted image 20240926093931.png]]
- The benefits of this approach is that it is simple. Once we have correctly developed the application, we can just spawn multiple processes and run it in each process.
## Cons
- The downside of running multiple processes in a platform is that there is a higher memory footprint, which can hurt performance.
- In addition, we have to pay the high cost of a context switch whenever we want to run a different process.
- As well as, it can be hard/costly to maintain shared state across processes due to IPC constraints. 
- Finally, it may be difficult to have multiple processes listening on a specific port.

