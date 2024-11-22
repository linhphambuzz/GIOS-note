
![[Pasted image 20241122063748.png]]


## Replication 

With replication, the filesystem can be replicated onto multiple machines, such that each machine holds all the files.

The benefit of this is that client requests can be load balanced across all machines, which can lead to better performance. In addition, the system overall can be more available. Finally, this system is more fault tolerant. When one replica fails, the other replicas can serve clients with no degradation of service.

The downside of this approach is that writes become more complex. One solution is to force clients to write synchronously to all replicas. Another solution involves writing to one replica, and then having a background job asynchronously propagate the write to the other replicas.

If replicas get out of sync, they must be reconciled. One simple reconciliation technique is voting, where the majority wins.


## Partitioning

With partitioning, every machine has a subset of all of the files in the system. Partitioning may be based on filename, file type, directory, or some other grouping.

The main benefit of this approach is that it allows for better scalability as the size of the filesystem grows. With the replicated approach, adding more machines does not mean that you can support a larger filesystem. With the partitioned approach, more machines does mean more files.

As well, writes are simple. Since a single file only lives on a single machine, writes to that file are localized to that machine.

A main downside of this approach is that when a partition goes down, the data stored on that partition can no longer be accessed.

In addition, balancing the system is more difficult, because we have to take into consideration how the particular files are accessed. If there is a particular file that is more frequently accessed by most clients in the system, we can run into the issue of **hotspots**.


## Combining 

Finally, we can have a solution where the filesystem is partitioned across some axis, and then each partition is replicated some number of times.

