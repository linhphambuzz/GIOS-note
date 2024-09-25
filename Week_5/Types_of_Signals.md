![[Pasted image 20240921154358.png]]
There are two types of signals.

**One-shot signals** refer to signals that will only interrupt once. This means that from the perspective of the user level thread, n signals will look exactly like one signal. One-shot signals must also be explicitly re-enabled every time. Whenever a handler is installed, it must be called explicitly 

**Real-Time Signals** refer to signals that will interrupt as many times are they are raised. If n signals occur, the handler will be called n times.

QUIZ: # P2L4: Thread Design Considerations: Signals Quiz -> review signals 
![[Pasted image 20240921155348.png]]

