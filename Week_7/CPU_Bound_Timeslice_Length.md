## Scenario 

- Let's consider two CPU bound tasks that each take 10 seconds to complete. 
- Let's assume that the time to context switch is 0.1 seconds. Let's consider a timeslice value of 1 second and a timeslice value of 5 seconds.

![[Pasted image 20241006110131.png]]
- With a smaller timeslice value, we have to pay the time cost of context switching more frequently. This will degrade our throughput and our average completion time. That being said, smaller timeslices mean that tasks are started sooner, so our average wait time is better when we have smaller timeslices.
- The user cannot really perceive when a CPU bound task starts, so average wait time is not super important for CPU bound tasks. The user cares when a CPU bound task completes.
- For CPU bound tasks, we are better off choosing a larger timeslice. In fact, if our timeslice value was infinite - that is to say we never preempt tasks - our metrics would be best.


## Full Calculations 
- timeslice= 1 sec
```

- throughput = 2 / (10 + 10 + 19*0.1) = 0.091 tasks/second
- avg. wait time = (0 + (1+0.1)) / 2 = 0.55 seconds
- avg. comp. time = 21.35 seconds=[ (18*1.1+1) + 1.1 + (18*1.1+1) ] /2  
```
- timeslice=  5 sec
```
- throughput = 2 / (10 + 10 + 3*0.1) = 0.098 tasks/second
- avg. wait time = (0 + (5+0.1)) / 2 = 3.05 seconds
- avg. comp. time = 17.75 seconds=[ (5.1*2 +5) + 5.1+ (5.1*2 +5)] /2
```

- timeslice= infinite 
```
- throughput = 2 / (10 + 10) = 0.1 tasks/second
- avg. wait time = (0 + (10)) / 2 = 5 seconds
- avg. comp. time = (10 + 20)/2 = 15 seconds

```