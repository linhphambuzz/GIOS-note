## Signal/ Interrupts Mask
- Interrupts and signals are handled in the context of the thread being interrupted/signaled. This means that they are handled on the thread's stack, which can cause certain issues.
- When a thread handles a signal, the program counter of the thread will point to the first address of the handler. The stack pointer will remain the same, meaning that whatever the thread was doing before being interrupted will still be on the stack.
- If the handling code needs to access some shared state that can be used by other threads in the system, we will have to use mutexes. 
- If the thread which is being interrupted had already locked the mutex before being interrupted, we are in a **deadlock**. The thread can't unlock its mutex until the handler returns, but the handler can't return until it locks the mutex.
- To prevent this situation, we can enforce that the handling code stays simple and make sure it doesn't do things like try to acquire mutexes. This of course it too restrictive.
- ![[Pasted image 20240921153034.png]]
-> A better solution is to use **signal/interrupt masks**. These masks allow us to dynamically make decisions as to whether or not signals/interrupts can interrupt the execution of a particular thread.
- The mask is a sequence of bits where each bit corresponds to an interrupt or signal and the value - 0 or 1 - signifies whether or not this particular interrupt or signal is disabled or enabled.
- When an event occurs, first the mask is checked to determine whether a given interrupt/signal is enabled. If the event is enabled, we proceed with the actual handling code. If the event is disabled, the interrupt/signal is made pending and will be handled at a later time when the mask changes.

## Solving Deadlock
- To solve the deadlock situation, described above, we must disable the interrupt/signal before acquiring the mutex. Disabling will place them into the pending state. we will re-enable the interrupt/signal after releasing the mutex. This will ensure that we are never in the handler code when the mutex is locked.
- Once the signal is re-enabled, the pending signal is handled by the handler.
- ![[Pasted image 20240921153406.png]]
- While an interrupt or signal is pending, other interrupts or signals may also become pending. **Typically the handling routine will only be executed once, so if we want to ensure a signal handling routine is executed more than once, it is not sufficient to just generate the signal more than once.**

## More on Masks
![[Pasted image 20240921153648.png]]
- Signal mask: depends on what the User ;evel thread is doing at the particular monment