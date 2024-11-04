
- spinklock: basic  sync construct 
- how is it implemented? what opportunities to use it -> alternative implementations of spin locks, genera technique of atomic construct to other construct 
![[Pasted image 20241102121938.png]]

- inefficient because it keeps spinging when lock isn't free
- incorrect because race condition

![[Pasted image 20241102122402.png]]