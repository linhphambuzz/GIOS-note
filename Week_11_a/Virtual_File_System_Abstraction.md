- The **file** abstraction represent the elements on which the VFS operates.
## File Descriptor
- The OS abstracts files via **file descriptors**. A file descriptor is an integer that is created when a file is first opened. There are many operations that can be supported on files using a file descriptor, such as `read`, `write` and `close`.
## Inode
- For each file the VFS maintains a persistent data structure called an **inode**. 
- The inode maintains a list of all of data blocks corresponding to the file.
- In this way, the inode is the "index node" for a file. 
- The inode also contains other information for that file, like permissions associated with the file, the size of the file, and other metadata. 
- Inodes are important because file do not need to be stored contiguously on disk. Blocks for a file may exist all over the storage media, making it important to maintain this index.
## dentry
- To help with certain operations on directories, Linux maintains a data structure called a **dentry** (directory entry). 
- Each dentry object corresponds to a single path component that is being traversed as we are trying to reach a particular file. 
- For instance, if we are trying to access a file in `/users/ada`, the filesystem will create a dentry for every path component - for `/` , `/users` and `/users/ada`.
- This is useful because when we need to find another file in `/users/ada`, we don't need to go through the entire path and re-read the files that correspond to all of the directories in order to get to the `/users/ada` directory. 
### dentry cache
- The filesystem will maintain a **dentry cache** containing all of the directories that we have previously visited. Note that dentry objects live only in memory (i.e:soft state) ; they are not persisted.

## Superblock 
- the **superblock** abstraction provides information about how a particular filesystem is laid out on some storage device. 
-  The data structure maintains a map that the filesystem uses so it can figure out how it has organized the persistent data elements like inodes and the data blocks that belong to different files.
- Each file system maintains some additional metadata in the superblock. Different file systems store different metadata.

