![[Pasted image 20241121151817.png]]

Modern operating systems export a high-level filesystem interface to abstract all of the (potentially) different types of storage devices present on a machine and unify them under a common API.

The OS can hide the fact that there isn't even local physical storage on a machine; rather, the files are maintained on a remote filesystem that is being accessed over the network.

Environments that involve multiple machines for the delivery of the filesystem service are called **distributed filesystems** (DFS).


