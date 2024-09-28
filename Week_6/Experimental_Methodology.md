
To achieve a good experimental design you need to answer a few questions.

- What systems are you comparing? Are you comparing two software implementations? If so, keep the hardware the same. Are you comparing two hardware platforms? Make sure the software is consistent.

- What workloads will you use? What are the inputs on the system? Will you be able to use data that may be expected/gathered from the real world, or will dummy data be used?

- Finally, how will you measure performance? Will you look at execution time, throughput or something else? Who are you designing the system for?

![[Pasted image 20240927085230.png]]

## Define Metrics 
![[Pasted image 20240927085932.png]]
- Bandwidth:  Bandwidth measures the total number of bytes transferred divided by the total amount of time it takes to transfer those bytes.
- Connection Rate: because the authors were concerned with Flash's ability to perform concurrent processing, they wanted to see the impact of **connection rate** as a metric. This is defined as the total number of client connections serviced divided by the total amount of time that passed.
- Both of these metrics were evaluated as a function of file size. The intuition is that with a larger file size, the connection cost can be ammortized, resulting in higher bandwidth. On the other hand, with a larger file size, there is more work to do per connection, so it's expected that there will be a lower connection rate.

