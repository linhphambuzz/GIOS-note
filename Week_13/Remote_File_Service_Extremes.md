
## Extreme 1 : Upload/ Download 

![[Pasted image 20241121152921.png]]

- When a client wants to access a file, it downloads the entire file, performs the modifications and then uploads the entire file back to the server.
- The benefit of this model is that all of the modifications can be done locally, which means they can be done quickly, without incurring any network cost.

- One downside of this model is that the client has to download the entire file, even for small modifications. A second downside of this model is that it takes away file access control from the server. Once the server gives the file to the client, it has no idea what the client is doing with the file or when it will give it back.
## True Remote File Access
![[Pasted image 20241121153222.png]]
- At the other extreme, we have the true remote file access. In this model, the file remains on the server and every single operation has to pass through the server. The client makes no attempt to leverage any kind of local caching or buffering.
- The benefit of this extreme is that the server now has full control and knowledge of how the clients are accessing and modifying a file. This makes it easier to ensure that the state of the filesystem is consistent.

- The downside of this model is that every file operations pays a network cost. In addition, this model is limited in its scalability. Since every file operation goes to the server, the server will get overloaded more quickly, and will not be able to service as many clients.

