
## Hardware-specific 

Each type of hardware will support a number of atomic instructions. Some examples include

- `test_and_set`
- `read_and_increment`
- `compare_and_swap`
-> Each of these operations performs some multi step, multi cycle operation. Because they are atomic instructions, however, the hardware makes some guarantees
1. these operations will happen atomically; that is, completely or not at all.
2. the hardware guarantees mutual exclusion - threads on multiple cores cannot perform the atomic operations in parallel. 
3. All concurrent attempts to execute an instruction will be queued and performed serially.

-> atomic instructions are critical sections and hardware supports synchronization 

## Test & Set 

```
spinlock_lock(lock) {
	while(test_and_set(lock) == busy);
}
```
- When the first thread arrives, `test_and_set` looks at the value that `lock` points to. 
- This value will initially be zero. `test_and_set` atomically sets the value to one, and returns zero.
- Thus, the first thread can proceed.
- When subsequent threads arrive, `test_and_set` will look at the value - which is set - and just return it. These threads will spin.


![[Pasted image 20241102124132.png]]

Which specific atomic instructions are available on a given platform varies from hardware to hardware. There may be differences in the efficiencies with which different atomic operations execute on different architectures. For this reason, software built with specific atomic instructions needs to be ported; that is, we need to make sure the implementation uses one of the atomic instructions available on the target platform. We also have to make sure that the software is optimized so that it uses the most efficient atomics on a target platform and uses them in an efficient way