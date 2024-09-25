![[Pasted image 20240912202319.png]]

- A layered model of multithreading is one in which similar subtasks are grouped together into a "layer" and the threads that are assigned to a layer can perform any of the subtasks in that layer. The end-to-end task must pass through all the layers.

- A benefit of this approach is that we can have specialization while being less fine-grained than the pipeline pattern.

- Downsides of this approach include that it may not be suitable for all applications and that synchronization may be more complex as each layer must know about the layers above and below it to both receive inputs and pass results.