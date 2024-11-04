- We covered issues related to correctness and ease-of-use. 
### common pitfall of mutexes and cond variables 
- For example, we talked about how easy it is to unlock the wrong mutex or signal on the wrong condition variable. The use of mutexes and condition variables is not an error proof process.
- we had to introduce a proxy variable to encapsulate the various states of our application. We needed this helper variable because mutexes by themselves can only represent simply binary states: they lack expressive power. We cannot express arbitrary synchronization conditions using the constructs we have seen already.

## Atomic instructions 
- Synchronization constructs require low level support from the hardware in order to guarantee the correctness of the synchronization construct. Hardware provides this type of low level support via **atomic instructions**.