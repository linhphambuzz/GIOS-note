Here is the XDR specification for a simple program in which the client sends an integer `x` to the server and the server squares it.

![[Pasted image 20241116134442.png]]

## Datatypes
In the .x file, the server specifies all of the datatypes that are needed for the arguments and the results of the procedures that it supports.

In this case, the server supports one procedure `SQUARE_PROC` that has one argument of the type `square_in`, and returns a result of the type `square_out`.

The datatypes `square_in` and `square_out` are both defined in the .x file. They are both structs that have one member that is an `int`, which is just like the `int`s in C.

## Services 
In addition to the data types, the .x file describes the actual RPC service and all of the procedures that it supports.
First, there is the name of the RPC service, `SQUARE_PROG`, that will be used by clients trying to find an appropriate service to bind with.

A single RPC server can support one or more procedures. In our case, the `SQUARE_PROG` service supports one procedure `SQUARE_PROC`. There is an ID number associated with a procedure that is used internally by the RPC runtime to identify which particular procedure is being called.

In addition to the procedure ID, and the input and output data types, each procedure is also identified by a version. The version applies to an entire collection of procedures.

Finally, the .x file specifies a service id. This id is a number that is used by the RPC runtime to differentiate among different services.



![[Pasted image 20241116134627.png]]


The client will use service name, procedure name, and service number, whereas the RPC runtime will refer to the service id, procedure id, and the version id.