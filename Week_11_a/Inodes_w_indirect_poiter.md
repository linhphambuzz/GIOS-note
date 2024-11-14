
One way to solve the issue of file size limits is to use **indirect pointers**.

![[Pasted image 20241105135045.png]]

The first section of blocks contain blocks that point directly to data. The direct pointers will point to 1kb per entry.

To extend the number a disk blocks that can be addressed via a single inode element, while also keeping the size of the inode small, we can use indirect pointers.

## indirect pointer 
- An indirect pointer will point to a block of pointers, where each pointer points to data. Given that a block contains 1kB of space, and a pointer is 4B large, a single indirect pointer can point to 256KB of file content.
- A double indirect pointer will point to a block of single indirect pointers, while will point to pointers to data. This means that a single double indirect pointer can point to 256_256_1KB = 64MB of file content.

## Pros 
- The benefits of indirect pointers is that it allows us to use relatively small inodes while being able to address larger and large files.

## Cons
The downside of indirect pointers is that file access is slowed down. Without any indirect pointers, we have at most two disk accesses to get a block of content: one access for the inode, one access for the block. With double indirect pointers, we double the number of accesses we need to make: inode + block + two pointers.

