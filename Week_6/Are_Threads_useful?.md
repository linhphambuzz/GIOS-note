![[Pasted image 20240925174846.png]]

Threads are useful for a few reasons. :
1. They allow us to have speed up because we can parallelize problems.
2. We get to benefit from a hot cache because we can specialize what a particular thread is doing. 
3. Using threads leads to implementations that have lower memory requirements and are cheaper to synchronize than implementations that are multiprocess. 
4. Threads are useful even on a single CPU because they allow us to hide latency of I/O operations.
## What is useful?
![[Pasted image 20240925175326.png]]

For a matrix multiply application, we may care about the raw _execution time_ of the application. For a web server application, we might care about the _throughput_ of the application (number of requests/time) or we might care about the _response time_. For a hardware chip, we might care about the overall _utilization_ increase of the hardware.

For any of these metrics, we might care about the average value, or the max/min value, or maybe even the value at a certain percentage. For example, we may consider that an application that completes a task in 3ms 95% of the time to be sufficient.
### Metrics 

To evaluate some solution, and determine whether it is useful or not, it is important to determine the properties that we really care about. We call such properties **metrics**.

