![[Pasted image 20241104210611.png]]
- The virtual file system data structures are software entities. They are created and maintained by the operating system file system component.
- Other than the dentries, the remaining components of the filesystem will correspond to blocks that are present on disk. The files are written to disk as blocks. The inodes - which track all of the blocks that correspond to a file - are persisted as well in a block.
- To make sense of all of this - that is, to understand which blocks hold data, which blocks hold inodes and which blocks are free - the superblock maintains an overall map of all of the disks on a particular device. This map is used both for allocation and lookup.

