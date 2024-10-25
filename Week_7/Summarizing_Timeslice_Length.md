- CPU bound tasks prefer longer timeslices as this limits the number of context switching overheads that the scheduling will introduce. This ensures that CPU utilization and throughput will be as high as possible.
- On the other hand, I/O bound tasks prefer short timeslices. This allows I/O bound tasks to issue I/O requests as soon as possible, and as a result this keeps CPU and device utilization high and well improves user-perceived performance (remember wait times are low).

