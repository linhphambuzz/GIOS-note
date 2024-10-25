![[Pasted image 20241005190503.png]]
- Consider the following setup assuming an SJF policy with priority, where P3 < P2 < P1.
- Initially, T3 is the only task in the system, so it begins executing. Suppose it acquires a mutex. T2 now arrives, which has higher priority than T3, so T3 is preempted and T2 begins to execute. Now T1 arrives and preempts T2. Suppose T1 needs the lock that T3 holds. T1 gets put on the wait queue for the lock and T2 executes. T2 finishes and T3 executes. Once T3 finishes and unlocks the mutex, T1 can finally run.

- We see that we have a case of **priority inversion** here because T1 which has the highest priority is now waiting on T3 which has the lowest priority. The order of execution should have been T1, T2, T3, but instead was T2, T3, T1.
# Solution
- A solution to this problem would have been to temporarily boost the priority of the mutex owner. 
- When T1 needs to acquire the lock owned by the T3, T3 should have its priority boosted to P1, so it would be scheduled on the CPU. So we didn't have to wait for T2
- Once T3 releases its mutex, T3 should have its priority dropped back to P3, so T1 can now execute, as T1 is the task with the actual highest priority.