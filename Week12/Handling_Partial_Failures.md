![[Pasted image 20241115135411.png]]

When a client hangs while waiting on a remote procedure call, it is often difficult to pinpoint the problem.

Is the server down? Is the service down? Is the network down? Is the message lost?

Even if the RPC runtime incorporates some timeout/retry mechanisms, there are still no guarantees that the problem will be resolved or that the runtime will be able to provide some better insight into the problem.

RPC systems incorporate a special error notification that tries to capture what went wrong with an RPC request without claiming to provide the exact detail. This serves as a catch all for all types of (partial) failures that can potentially happen during an RPC call.

![[Pasted image 20241115135614.png]]


## Summary of RPC design choices 

![[Pasted image 20241115135917.png]]