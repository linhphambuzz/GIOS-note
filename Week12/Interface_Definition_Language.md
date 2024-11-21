
When using RPC, the client and the server don't need to be developed together. The can be written by different developers in different programming languages.

For this to work, however, there must be some type of agreement so that the server can explicitly say what procedures it supports and what arguments it requires.

This information is needed so that the client can determine which server it needs to bind with.

Standardizing how this information is represented is also important because it allows the RPC runtime to incorporate some tools that allow it to automate the process of generating the stub functionality.

To address these needs, RPC systems rely on the use of **interface definition languages** (IDLs). The IDL serves as a protocol of how the client-server agreement will be expressed.

