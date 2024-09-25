- Make sure to keep track of the mutex/condition variables that are used with a given shared resource. Comments help!
- Make sure to always protect access to shared state, and make sure to do so consistently by acquiring the **same** mutex. A common mistake occurs when we forget to lock or unlock a mutex associated with a given piece of state. Compilers may generate warnings/errors to help us.
- Don't use different mutexes to access a single resource. Using different mutexes to access a resource is akin to just not using a mutex at all, since there is no mutual exclusion amongst different mutexes. Use a single mutex to access a single resource. 
- ![[Pasted image 20240912193956.png]]
- Make sure that you are signaling or broadcasting on the correct condition. Signaling that reads can occur when you should be signaling that writes can occur can impact the correctness of your program.
- Make sure to not use signal when broadcast needs to be used. Note that the opposite is actually okay (although it may incur a performance penalty).
- Remember that the order of execution of threads is not related to the order in which we call signals or broadcasts. If priority/ordering guarantees are needed, other strategies must be devised.

## [](https://www.omscs-notes.com/operating-systems/threads-and-concurrency/#spurious-wake-ups)