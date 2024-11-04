![[Pasted image 20241103210847.png]]

- The atomic operation involves the variable `queuelast`, but the rest of the locking code doesn't involve that variable. 
- Any kind of invalidation traffic will not concern any of the spinning on the flags array. These are different memory allocations 

## Latency 

- From a latency perspective, this lock is not very efficient. It performs a more complex atomic operation, `read_and_increment` which takes more cycles than a standard `test_and_set`.
- Modulos takes more time 

## Delay 
- From a delay perspective, this lock is good. Each lock holder directly signals the next element in the queue that the lock has been freed.

## Contention
- From a contention perspective, this lock is much better than any locks we have discussed, since the atomic is only executed once up front and is not part of the spinning code. The atomic operation and the spinning code involve separate variables, so cache invalidation on the atomic variable doesn't impact spinning.
- In order to realize these contention gains, we must have a cache coherent architecture. Otherwise, spinning must involve remote memory references. In addition, we have to make sure that every element is on a different cache line. Otherwise, when we change the value of one element in the array, we will invalidate the entire cache line, so the processors spinning on other elements will have their caches invalidated.
![[Pasted image 20241103212535.png]]