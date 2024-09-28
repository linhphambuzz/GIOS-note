For the best case, the authors used the synthetic load. They varied the number of requests that were made, but made sure each request asked for the exact same file. The is the best case because once the file is requested once, it can be cached which means that subsequent requests for the file will be answered much more quickly.

For the best case experiment, they vary the file size from 0 to 200kb, and they measure the bandwidth which is the number of requests times the file size divided by the total time. By varying the file size, they vary the amount of work that the server has to do on a given request.

## Observations 
- SPED (single process event driven): best performance because no ctx switch. 
- Flash is similar in performance, but it performs the extra check for memory presence.
- Zeus has an anomaly, where it drops in performance after a threshold of around 125Kb.
- he performance of the multithreaded/multiprocess implementations are lower because of the extra synchronization requirements and the cost of context switching. 
- Apache has the lowest performance because it has no optimizations.

![[Pasted image 20240927095333.png]]

## Owlnet Trace 
- For the Owlnet trace, the results are mostly similar to the best case. We can see that Flash and SPED are the best, followed by MT/MP and then Apache. 
- The reason for this trend is because the owl trace is very small, so most of the requests can be serviced from the cache
- ![[Pasted image 20240927095522.png]]
-  However, not everything can be serviced from cache, so sometimes blocking I/O is required. In this case, SPED will block, but Flash will not because it has helpers. This helps explain why Flash's performance is slightly higher than the SPED implementation.

## CS traces

![[Pasted image 20240927095833.png]]
- The CS trace is a much larger trace, which means that most requests are not serviced from the cache. Since the SPED implementation does not support asynchronous I/O the performance drops significantly. 
- The multithreaded implementation does better than the multiprocess implementation because it has a smaller memory footprint (more memory available to cache files) and is able to synchronize more quickly/cheaply.
- Flash performs the best. It has the smallest memory footprint, which means it has the most memory available for caching files.

## Impact of Optimizations 

![[Pasted image 20240927105954.png]]

We can see that in all cases, connection rate decreases with file size. That being said, connection rate increases as the number of optimizations increase, with the fully optimized flash having the highest connection rate at a given file size. Optimizations are important!


## Summary 
![[Pasted image 20240927111053.png]]

- When the data is in cache, SPED performs better than AMPED Flash, since AMPED Flash makes an "unnecessary" test for memory presence on each request. 
- Both SPED and AMPED Flash perform better than MT/MP models, because neither occurs any synchronization or context switching overhead.
- When the workload is disk-bound, AMPED Flash performs much better than SPED, which blocks on I/O request because it doesn't have asynchronous I/O. 
- AMPED Flash performs better than MT/MP because the more efficient memory implementation leaves more memory available for caching.


