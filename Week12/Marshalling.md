To understand marshaling, let's look at the `add` example again, with arguments `i` and `j`. Initially, `i` and `j` live somewhere in the client address space. When the client calls the add function, it passes in `i` and `j` as discrete entities.

At the lowest level, a socket will need to send a contiguous buffer of information over to the server. This buffer will need to hold a descriptor for the procedure (`add`) to be called on the server, as well as the necessary arguments, `i` and `j`.

This buffer gets generated by the marshaling code.

Generally, the marshaling process encodes the data into an agreed upon format so that it can be correctly interpreted by the server. This encoding specifies the layout of the data upon serialization into a byte stream.

![[Pasted image 20241115131056.png]]