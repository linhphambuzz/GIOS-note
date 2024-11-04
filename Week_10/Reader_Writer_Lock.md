When specifying synchronization requirements, it is sometimes useful to distinguish among different types of resource access.

For instance, we commonly want to distinguish "read" accesses - those that do not modify a shared resource - from "write" accesses - those that do modify a shared resource. For read accesses, a resource can be shared concurrently while write accesses requires exclusive access to a resource.

This is a common scenario and, as a result, many operating systems and language runtimes support a construct known as **reader/writer** locks.

## Using RW Locks 

![[Pasted image 20241102110331.png]]

- Reader/writer locks are supported in many operating systems and language runtimes. However, the semantics may be different across different environments.
- Some implementations refer to reader/writer locks as **shared/exclusive** locks.
## The differences 
- Implementations may differ on how recursively-obtained read locks are unlocked. When unlocking a recursive read lock, some implementations unlock all the recursive locks, while others only unlock the most recently acquired lock.
- Priority in upgrading/downgrading : Some implementations allow readers to convert their lock into a writer lock mid-execution, while other implementations do not allow this upgrade.
- Some implementations block an incoming reader if there is a writer already waiting, while others will let this reader acquire its lock.

