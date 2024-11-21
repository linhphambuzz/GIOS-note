
![[Pasted image 20241115140130.png]]

SunRPC is an RPC package originally developed by Sun in the 1980s for UNIX systems. It is now widely available on other platforms.

SunRPC makes the following design choices.

## Registry 

In SunRPC, it is assumed that the server machine is known up front, and therefore the registry design choice is such that there is a registry per machine. When a client wants to talk to a particular service, it must first talk to the registry on that particular machine.

## IDL 

SunRPC makes no assumption regarding the programming language used by the client or the server. Sun RPC relies on a language-agnostic IDL - XDR - which is used both for the specification of the interface and for the specification of the encoding of data types.

## Pointers 

SunRPC allows the use of pointers and serializes the pointed-to data.

## Errors Handling 

SunRPC supports mechanisms for dealing with errors. It includes a retry mechanism for re-contacting a server when a request times out. The number of retries can be specified
The RPC runtime tries to return meaningful errors as often as possible.

