![[Pasted image 20241105134715.png]]
- Inodes play a key role in organizing how files are stored on disk because they essentially integrate an index of all of the disk blocks that correspond to a particular file.
- A file is uniquely identified by its inode. The inode contains a list of all of the blocks that correspond to the actual file. In addition to the list of blocks, an inode also contains additional metadata information.
- The file shown above has 5 blocks allocated to it. If we need more storage for the file, the filesystem can allocate a free block, and simply update the inode to contain a sixth entry, pointing to the newly allocated block.
## Pros
- The benefit of this approach is that it is easy to perform both sequential and random accesses to the file.
## Cons

- The downside of this approach is that there is a limit on the file size for files that can be indexed using this data structure. 
- For example, if we have a 128B inode containing 4B block pointers, we can only address 32 blocks. If each block can store 1Kb of information, our file size limit is 32Kb, which is too restrictive.

