
The ext2 filesystem was the default filesystem in Linux until it was replaced by ext3 and ext4 more recently.

A disk partition that is used as a ext2 Linux filesystem looks as follows.

![[Pasted image 20241104211450.png]]
- The first block is not used by Linux and is often used to boot the system.
- The rest of the partition is divided into block groups. The size of these block groups have no correlation to the physics of the actual disk these group abstract.
- The first block is the super block, which contains information about the overall block group:

	- number of inodes
	- number of disk blocks
	- start of free blocks
- The overall state of the block group is further described by the group descriptor, which contains information about:

	- bitmaps
	- number of free nodes
	- number of directories
Bitmaps are used to quickly find free blocks and inodes. Higher level allocators can read the bitmaps to easily determine which blocks and inodes are free and which are in use.

- The inodes are numbered from 1 to some maximum value. Every inode in ext2 is a 128B data structure that describes exactly one file. The inode will contain information about file ownership as well as pointers to the actual data blocks that hold the data (sthing that returned by stat syscall), how to locate data block
- Data blocks: the actual data blocks themselves that hold the data.  reminder that a directory is just a file except that in the upper levels of the file system software stack there will be the dentry data structures created for each partricular component fo reach particular directory 