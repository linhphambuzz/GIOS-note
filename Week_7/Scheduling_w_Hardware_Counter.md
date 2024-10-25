
- Fedorova speculates that a more concrete metric to help determine if a thread is CPU bound or memory bound is **cycles per instruction** (CPI). 
- A memory bound thread will take a lot of cycles to complete an instruction; therefore, it has a high CPI. 
- A CPU bound thread will have a CPI of 1 (or some low number) as it can complete an instruction every cycle (or close to every cycle).
- Given that there is no CPI counter on the processor that Fedorova uses - and computing something like 1 / IPC would require unacceptable software intervention - she uses a simulator.

## Test Bed 
- Fedorova simulates a system that has 4 cores, with each core have a 4-way SMT, for a total of 16 hardware execution contexts.
-  she wants to vary the threads that get assigned to these hardware contexts based on their CPI, so she creates a synthetic workload where her threads have a CPI of 1, 6, 11, and 16. The threads with the CPI of 1 will be the most CPU-intensive, while the threads with the CPI of 16 will be the most memory-intensive. The overall workload mix has four threads of each kind.
- She wants to assess is the overall performance when a specific mix of threads gets assigned to each of these 16 hardware contexts, and she uses IPC as the metric. Given that the maximum number of cores is 4, the maximum IPC is 4.
![[Pasted image 20241008120849.png]]

## Result 

![[Pasted image 20241008183333.png]]
- In the first two experiments, we have a fairly well balance mix of high- and low-CPI threads across the cores. We see that in these two cases, the processor pipeline was well-utilized and our IPC is high.
- In the last two experiments, each of the cores were assigned tasks with similar - or in the case of the final experiment, identical - CPI values. We can see that in these two cases, the processor pipeline was much more poorly utilized. Threads either spent a lot of time in contention with one another - in the case of CPU bound tasks - or the CPU spent a lot of time idling - in the case of memory-bound tasks. Regardless, our IPC dropped significantly.
-> We can conclude that scheduling tasks with mixed CPI values leads to higher platform utilization.


![[Pasted image 20241008184115.png]]


What we can see is that most of the values are quite cluttered together. We do not see the distinct values presented in the synthetic workload. Most CPIs range from 2.5 - 4.5.

Because CPI isn't that different across applications, it may not be the most instructive metric to inform scheduling decisions.

![[Pasted image 20241008184819.png]]