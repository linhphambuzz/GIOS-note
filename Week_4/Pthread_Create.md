To represent threads, pthreads supports a `pthread_t` data type. Variables of this type will be uniquely identified by an identifier and will describe a thread.

```
int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void * (*start_routine)(void *), void *arg);
```

`pthread_t *thread` : a pointer to pthread_t 
`(*start_routine)(void *)`: the start routine 
`void *arg`: argument to pass to the routine 
`pthread_attr_t` which is a data structure that can be used to set various options on the thread during creation.

`pthread_create` returns an `int` which indicates whether the creation was a success or a failure.
- Child threads can be joined back to a parent thread with

```
int pthread_join(pthread_t thread, void **status)
```

This function takes the thread to be joined as well as a status variable. The status variable will capture all of the important information that is returned from the thread to be joined.

`pthread_join` returns an `int` which indicates whether the join was a success or a failure.

### P_thread Atributes 

The `pthread_attr_t` data structure allows us to define features of the new thread we are creating, such as:

- stack size
- scheduling policy
- priority
- system/process scope
- inheritance
- joinable


If `NULL` is passed in the place of a `pthread_attr_t`, pthreads falls back to default behavior for the new thread.

There are several calls that allow us to operate on a `pthread_attr_t`

```
int pthread_attr_init(pthread_attr_t *attr);
int pthread_attr_destroy(pthread_attr_t *attr);
pthread_attr_{set/get}{attribute};
```


These functions can be used, respectively: 
1. to allocate space for a `pthread_attr_t` 
2. to deallocate space for that `pthread_attr_t` 
3. to set/get various attributes of that structure.

## Detachable thread 


- One mechanism not considered by Birrell is **detachable threads**. In pthreads, the default behavior for thread creation is joinable threads. For a joinable (child) thread, the parent will not terminate until the child has completed their execution. If the parent thread exits early, the child threads may turn into zombies.

- In pthreads, it is possible to allow child threads to become detached. Detached threads cannot be joined back into the parent, allowing the parent to exit early and the child threads to continue their execution.


```
int pthread_detach(pthread_t thread);
```

Or

```
pthread_attr_setdetachstate(attr, PTHREAD_CREATE_DETACHED);

// ...

pthread_create(..., attr, ...);
```

- Since parent threads do not need to wait around until child threads complete, they can simply exit with `pthread_exit`.
![[Pasted image 20240914151601.png]]
Last line should be:
```
pthread_create(&tid, &attr, foo, NULL);
```