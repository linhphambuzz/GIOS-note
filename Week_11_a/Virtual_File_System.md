- What if we want to make sure that a user application can seamlessly see files across multiple devices as a single, coherent filesystem?
- What if different types of devices work better with different filesystem implementations?
- What if files are not even local to a machine, and are accessed over the network?
![[Pasted image 20241104205122.png]]
- To solve the underlying problems that these questions pose, operating systems like Linux include a **virtual filesystem** (VFS) layer. This layer hides all details regarding the underlying filesystem(s) from the higher level consumers.
- Applications continue to interact with the VFS using the same POSIX API as before, and the VFS specifies a more detailed set of filesystem-related abstractions that every single underlying filesystem must implement.
