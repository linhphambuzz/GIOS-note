- A metric is a measurable or quantifiable property of a system that we are interested in that can be used to evaluate the system's behavior. 
- example:exec time
![[Pasted image 20240925175839.png]]


- **Wait time**: Often, we would like for the value of this metric to be low. We would like to wait as little as possible for our jobs to start executing
- **Throughput** helps us evaluate the utility of a platform; that is, how many tasks will the platform complete in a given unit of time. This can be evaluated in the context of a single server or as complex a system as an entire datacenter
- If I own the data center, throughput may not be the metric that I am exclusively interested in. I might also be interested in **platform efficiency**, which measures how well resources are utilized to in order to deliver a certain measure of throughput. This matters because I make money as a result of high throughput (completing work quickly), but I also spend money to maintain my platform. A higher measure of platform efficiency means I have to spend less on my platform.
- If I really just care about money, I can look at **performance per dollar**. If I want to know if I should buy the next greatest hardware platform, I should examine whether that cost that I incur in doing so will be offset by a boost in performance per dollar.

- Many times, I am more concerned about energy requirements. I might look at **performance per watt** when making decisions about new pieces of hardware. If my energy costs are high, maybe the right purchase is a machine that is more energy efficient.
- When looking to incorporate enterprise software into the system, another useful metric may be the **percentage of SLA violations**. It may not make sense to create a contract with a software company if the SLA violations on their products are very high.
- Some metrics are not super useful to maximize. For example, "smooth" video requires ~30fps. It doesn't make sense to maximize the fps, but rather the goal should be to stay above or around 30fps for some high percentage of the time. In this case **client-perceived performance** is the goal, not raw performance.
- ![[Pasted image 20240925180731.png]]
- n summary, a metric is some measurable quantity we can use to reason about the behavior of a system.

Ideally, we will obtain these measurements running real software on real machines with real workloads. Often, this is not feasible for many different reasons. In these cases, we may have to settle on "toy" experiments that are _representative_ of realistic situations that we may encounter.

We refer to these experimental settings as a **testbed**. The testbed tells us where/how the experiments were carried out and what were the relevant metrics being gathered.
