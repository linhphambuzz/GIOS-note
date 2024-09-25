- To deal with the mutual exclusion problem, pthreads supports mutexes. Mutual exclusion ensures that threads access shared state in a controlled manner, such that only thread at a time can apply modifications or otherwise access that shared variable.
- In pthreads, the mutex data structure is represented via a `pthread_mutex_t` type.

- In pthreads, there is no implicit unlock: both lock and unlock must be explicitly called.
![[Pasted image 20240915113429.png]]

```
int pthread_mutex_lock(pthread_mutex_t *mutex);
int pthread_mutex_unlock(pthread_mutex_t *mutex);
```
-> Whatever code appears between these two statements will correspond to the _critical section_.

![[Pasted image 20240915114128.png]]
Example of safe_insert()
## Other mutex's operation

![[Pasted image 20240915114305.png]]
- The `pthread_mutexattr_t *attr` argument allows us to specify the behavior that we want the mutex to have(for example: Mutex is shared among processes ). Passing `NULL` gives us the default behavior (similar to the case with `pthread_create` and `pthread_attr_t` where the mutex can only be visible in one process).


```
int pthread_mutex_trylock(pthread_mutex_t *mutex);
```
Unlike `pthread_mutex_lock` which will cause the calling thread to block, this function will return immediately if the mutex cannot be acquired.

Mutexes can be destroyed (freed) with: 

```
int pthread_mutex_destroy(pthread_mutex_t *mutex);
```



### Mutexes safety tips 

- shared data should always be accessed through single mutex
- mutex scope must be global (can't be private to only one thread)
- globally order locks - lock mutexes in order (to prevent deadlocks)
- always unlock the (correct) mutex

