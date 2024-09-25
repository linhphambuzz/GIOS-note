![[Pasted image 20240911152445.png]]

In summary, a pipeline is a sequence of stages, where a thread performs a stage in the pipeline, which is equivalent to some subtask within the end to end processing. To keep the pipeline balanced, a stage can be executed by more than one thread. Communication via shared buffers reduces coupling between the components of the system.

A key benefit of this approach is specialization and locality, which can lead to more efficiency, as state required for subsequent similar jobs is likely to be present in CPU caches.

A downside of this approach is that it is difficult to keep the pipeline balanced over time. When the input rate changes, or the resources at a given stage are exhausted, rebalancing may be required.
