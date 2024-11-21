## Typical Data types

All of the types defined in the XDR file must be XDR-supported data types.

Some of the default XDR data types include:

- char
- byte
- int
- float

XDR also support a `const` datatype which will get compiled into a `#define`'d value in C.

`hyper` values correspond to 64-bit integers and `quadruples` refer to 128-bit floats.

The `opaque` type corresponds to uninterpreted binary data, similar to the C byte type. For instance, if you wanted to transfer an image, that image could be represented as an array of opaque elements.


## Array 

![[Pasted image 20241117121926.png]]

### Fixed-length 

- A fixed length array looks like `int data[80]`.

### variable-length

- A variable-length array looks like `int data<80>`. 
- When compiled, this will translate into a data structure that has two fields: an integer `len` that corresponds to the actual size of the array, and a pointer `val` that is the address of where the data in this array is actually stored.
- When the data is sent, the sender has to specify `len` and set `val` to point to the memory location where the data is stored. On the receiving end, the server will know that it is expecting a data structure that is of variable length, so it will know to read the first four bytes to determine the length to determine the size of the array, and then to allocate the appropriate amount of memory and copy the remaining portion of the incoming byte stream into that buffer.
- The only exception to this **strings.** In memory, strings are stored as normal null-terminated strings. When the string is encoded for transmission, it will be stored as a par of `len` and `data`.
![[Pasted image 20241117123204.png]]
