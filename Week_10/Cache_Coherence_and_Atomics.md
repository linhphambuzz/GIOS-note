
- What happend with cached coherence when atomics instructions are used? 
![[Pasted image 20241102163814.png]]
- Let's consider a scenario in which we have two CPUs. Each CPU needs to perform an atomic operation concerning `X`, and both CPUs have a reference to `X` present in their caches.
- When an atomic instruction is performed against the cached value of `X` on one CPU, it is really challenging to know whether or not an atomic instruction will be attempted on the cached value of `X` on another CPU. We obviously cannot have incoherent cache references between CPUs: this will affect the correctness of our applications.
- **Atomic operations always bypass the caches and are issued directly to the memory location where the particular target variable is stored.**
## Benefit of going directly to memory 
- By forcing atomic operations to go directly to the memory controller, we enforce a central entry point where all of the references can be ordered and synchronized in a unique manner. None of the race conditions that could have occurred had we let atomic update the cache can occur now.
- That being said, atomic instructions will take much longer than other types of instructions, since they can never leverage the cache. Not only will they always have to access main memory, but they will also have to contend on that memory.
- *In addition, in order to guarantee atomic behavior*, we have to generate the coherence traffic to either update or invalidate all of the cached references to `X`, regardless of whether `X` changed. This is a decision that was made to err on the side of safety.
___
In summary, atomic instructions on SMP systems are more expensive than on single CPU system because of bus or I/C contention. In addition, atomics in general are more expensive because they bypass the cache and always trigger coherence traffic.

![[Pasted image 20241102164327.png]]


____________________
![[Pasted image 20241102165337.png]]