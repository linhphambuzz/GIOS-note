
## XDR 

In addition to providing an IDL, XDR also defines an encoding; that is, the binary representation of our data "on the wire".

## Encoding Rules
- All data types are encoded in multiples of four bytes. Encoding a single byte argument therefore would take and 3 bytes of padding. this help allignment moving to and from memory and packets
- Big endian is used as the transmission standard. Regardless of the endianness of the client or the server, every communication will require that the data be converted to the big endian representation prior to transmission.
- Other encoding rules include:

	- two's complement representation of integers
	- IEEE format for floating point numbers
- ![[Pasted image 20241120152743.png]]

![[Pasted image 20241120162841.png]]