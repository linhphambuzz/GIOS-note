
![[Pasted image 20240911123331.png]]
- The boss/workers pattern is characterized by having one boss thread and some number of worker threads. The boss is in charge of assigning work to the workers, and the workers are responsible for completing the entire task that is assigned to them.
- The throughput of the system is limited by the boss thread, since the boss has to do some work for every task that comes into the system.
- As a result it is imperative to keep the boss efficient to keep the overall system moving smoothly. Specifically, the throughput of the system is inversely proportional to the amount of time the boss spends on each task. (1/T)
### Solution 1
- **How does the boss assign work to the workers?** One solution is to keep track of which workers are currently working, and send a direct signal to a worker that is idle. This means that the boss must do some work for each worker, since it has to select a worker and then wait for that worker to accept the work.
- Pros: workers do not need to synchronize amongst each other.
- Cons: the boss must keep track of every worker, and this extra work will decrease throughput.

### Solution 2


![[Pasted image 20240911123604.png]]
- Another option is to establish a queue between the boss and the workers, similar to a producer/consumer queue. In this case, the boss is the sole producer, while the workers are consumers.
- Pros: boss doesn't need to know any of the details about the workers. It just places the work it accepts on the queue and moves on. Whenever a worker becomes free it just looks at the front of the queue and retrieves the next item.
- Cons: further synchronization is required, both for the boss producing to the queue, and the workers competing amongst one another to consume from the queue. Also for checking the front and back of the queue. 

->Despite this downside, this approach still results in decreased work for the boss for each task, which increases the throughput for the whole system.


## How many workers? 

- If the work queue fills up, the boss cannot add items to the queue, and the amount of time that the boss has to spend per task increases. The likelihood of the queue filling up is dependent primarily on the number of workers.
- Adding more threads may help to increase/stabilize the throughput, but adding an arbitrary number of threads can introduce complexities.
- We can create workers on demand; that is, in response to a new task coming into our system. This may be inefficient, though if the cost of creating a worker (thread) is significant.
- A more common model is to create a pool of workers that are initialized up front. The questions remains: how do we know how many workers we ought to create?

- A common technique is to use a pool of workers that can be increased in response to high demand on the system. This is not quite like the on demand approach in that new threads will not be created one at a time when the demand passes a threshold, but rather the pool may be doubled or increased by some other multiple.


## Pros 
The benefit of the boss/workers model is the overall simplicity. One thread assigns the work, and the rest of the threads complete it.

## Cons
- One downside of this approach is the thread pool management overhead. 
- Another downside is that this system lacks **locality**. The boss doesn't keep track of what any of the workers were doing last. It is possible that a thread is just finishing a task that is very similar to an incoming task, and therefore may be best suited to complete that task. The boss has no insight into this fact.

## Worker Variant 

- An alternative to having all the workers in the system perform the same task is to have different workers specialized for different tasks. 
- One added stipulation to this setup is that the boss has to do a little bit more work in determining which set of workers should handle a given task, but this extra work is usually offset by the fact that workers are now more efficient at completing their tasks.
- This approach **exploits locality**. By performing only a subset of the work, it is likely only a subset of the state will need to be accessed, and it is more likely this part of the state will already be present in CPU cache.
- In addition, we can offer better quality of service. We can create more threads for urgent tasks or tasks that have higher paying customers.
- One downside of this approach is the load balancing mechanisms and requirements may become more difficult to reason about.