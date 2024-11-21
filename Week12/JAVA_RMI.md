
![[Pasted image 20241121055313.png]]

## Java Remote Method Invocation 

Since Java is a an object-oriented language, and entities interact via method invocations, not procedure calls, the RPC system is appropriately called RMI instead.

Since all of the generated code is in Java, and the RMI system is meant for address spaces in JVMs, the IDL is language-specific to Java.

## Components 

- The **Remote Reference Layer** contains all of the common code needed to provide reference semantics. For instance, it can support unicast (a client interacting with a single server), or broadcast (a client interacting with multiple servers). In addition, this layer can specify different return semantics, like _return-first-response_ and _return-if-all-match_. As a dev you can specify the semantic you want from the RMI interactions, or you can implement just this component and rest of the semantic will remain the same. 
- The **Transport Layer** implements all of transport protocol-related functionality, whether TCP, UDP, shared memory or something else.