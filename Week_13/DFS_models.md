![[Pasted image 20241121152611.png]]
- A simple DFS model involves clients being served files from a server running on a different machine.
- Often, the server is not running on a single machine, but rather is distributed across multiple machines. Files may be **replicated** across every machine or **partitioned** amongst machines -> this makes the system more scalable than the replicated model
- In replicated systems, all the files are replicated and available on every server machine. If one machine fails, other machines can continue to service requests. Replicated systems are **fault tolerant**. In addition, requests entering a replicated system can be serviced by any of the replicas. Replicated systems are **highly available**.

- In partitioned systems, each server holds only some subset of the total files. If you need to support more files, you can just partition across more machines. In the replicated model, you will need to upgrade your hardware. This makes partitioned systems more **scalable**.
- It's common to see a DFS that utilizes both partitioning and replication; for example, partitioning all the files, and replicating each partition.

----
Finally, files can be stored on and served from all machines. This blurs the line between servers and clients, because all the nodes in the system are **peers**. Every node is responsible for maintaining the files and providing the filesystem service. Each peer will take some portion of the load by servicing some of the requests, often those that for files local to that peer.

