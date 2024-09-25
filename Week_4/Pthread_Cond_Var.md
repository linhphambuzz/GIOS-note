
![[Pasted image 20240915120346.png]]

- Condition variables are synchronization mechanisms that allow blocked threads to be notified when a certain condition occurs.

- In pthreads, condition variables are represented by the `pthread_cond_t` data type.

```
int pthread_cond_wait(pthread_cond_t *cond, pthread_mutex_t *mutex);
```

- **When a thread enters this function**, it immediately releases the mutex and places itself on the wait queue associated with the condition variable. 
- **When the thread is woken up**, it will automatically reacquire the mutex before exiting the wait operation.

## Signal/Broadcast 

To signal or broadcast on a condition variable we call

```
int pthread_cond_signal(pthread_cond_t *cond);
int pthread_cond_broadcast(pthread_cont *cond);
```

## Condition w Attributes, Free Cond 

To allocate/create a condition variable and de-allocate/destroy a condition variable, we can call: 

```
int pthread_cond_init(pthread_cond_t *cond, const pthread_condattr_t *attr);

int pthread_cond_destroy(pthread_cond_t *cond);
```

- `pthread_cond_init` takes some attributes that can further specify the behavior of the condition variable.
- If `NULL` is specified for attr, it will take the default behavior (i.e: private to only one process)
- `pthread_cond_destroy()` must be explicitly called 

![[Pasted image 20240915121413.png]]