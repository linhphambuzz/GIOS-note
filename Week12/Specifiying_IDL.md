## Definition
- An interface definition language is used to describe the interface that particular server exports. 
## What does it include?
- At a minimum, this will include the name of the procedure, the types of the different arguments and the result type.
- Another important piece of information to include is a version number. If there are multiple servers that provide the same procedure, the version number helps clients find which server is the most up to date. In addition, version numbers allow clients to identify the server which has the version of the procedure that fits with the rest of the client program.

## XDR 
- An RPC system can use an IDL that is language-agnostic. **SunRPC** uses an IDL called **eXternal Data Representation** (XDR). 
- XDR is a different specification from any programming language. 
- An RPC system can also use an IDL that is language-specific. For example, the Java RMI uses Java.
![[Pasted image 20241114233200.png]]

## IDL 

- For programmers that know the language, a language-specific IDL is great. For programmers that don't know that language, learning a language-agnostic IDL is simpler than learning a whole new programming language.

- Whatever the choice of IDL, the IDL is used solely to define the interface. The IDL is used to help the RPC system generate stubs and to generate information that is used in the service discovery process.

- The IDL is not used for the implementation of the service.

