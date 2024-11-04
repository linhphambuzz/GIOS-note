- This figures shows measurements that were gathered from executing a program that had multiple processes. Each process executed a critical section in a loop, one million times. The number of processes in the system was varied such that there was only one process per processor.
- The platform that was used was Sequent Symmetry, which has twenty processors, which explains why the number of processors on the graph is capped at 20. 
- This platform is cache coherent with write-invalidate.
## Metrics 
- The metric that was computed was the **overhead**, which was measured in comparison to a case of ideal performance, which corresponded to the theoretical limit - assuming no delay or contention - of how long it would take to execute the number of critical sections. 
- The measured difference between the theoretical limit and the observed execution time was the overhead.
## Highload 
- Lots of processors and lots of processes running, contending for the locks
- **The queueing lock** performs the best. It is the most scalable; as we add more processors, the overhead does not increase. 
- The `test_and_test_and_set` lock performs the worst under load. The platform is cache coherent with write-invalidate, and we discussed earlier how this strategy forces O(N^2) memory references to maintain cache coherence.
### Delay-based alternatives 
- The static locks are a little better than the dynamic locks, since dynamic locks have some measure of randomness and will have more collisions than static locks.
-  Also, delaying after every reference is slightly better than delaying after every lock release: bc when we avoid after reference, we avoiding additioinal invalidation for write invalidate architecture 

## Lighload 
- `test_and_test_and_set` performs pretty well: it has low latency. 
- We can also see that the dynamic delay alternatives perform better than the static ones. Static delay locks can naively enforce unnecessarily large delays under small loads, while dynamic alternatives adjust based on contention.
-  the queueing lock performs the worst: This is because of the higher latency inherent to the queueing lock, in the form of the more complex atomic, `read_and_increment`, as well as some additional computation that is required at lock time.