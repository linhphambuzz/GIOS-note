![[Pasted image 20240904085949.png]]
Let's look at a scenario where there is some subset of threads that want to read from shared state, and one thread that wants to write to shared state. This is commonly known as the **readers/writer** problem.

At any given point in time, 0 or more readers can access the shared state at a given time, and 0 or 1 writers can access the shared state at a given time. The readers and writer cannot access the shared state at the same time.

One naive approach would be to wrap access to the shared state itself in the mutex. However, this approach is too restrictive. Since mutexes only allow access to shared state one thread at time, we would not be able to let multiple readers access state concurrently.

Let's enumerate the conditions in which reading is allowed, writing is allowed, and neither is allowed. We will use a `read_counter` and a `write_counter` to express the number of readers/writers at a given time.

If `read_counter == 0` and `write_counter == 0`, then both writing and reading is allowed. If `read_counter > 0`, then only reading is allowed. If `write_counter == 1`, neither reading nor writing is allowed.

We can condense our two counters into one variable, `resource_counter`. If the `resource_counter` is zero, we will say that resource is free; that is, available for reads and writes. If the resource is being accessed for reading, the `resource_counter` will be greater than zero. We can encode the case where the resource is being accessed for writing by encoding `resource_counter` as a negative number.

Our `resource_counter` is a **proxy variable** that reflects the state that the current resource is in. **Instead of controlling updates to the shared state, we can instead control access to this proxy variable.** As long as any update to the shared state is first reflected in an update to the proxy variable, we can ensure that our state is accessed via the policies we wish to enforce.
