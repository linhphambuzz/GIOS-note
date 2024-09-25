![[Pasted image 20240904080804.png]]

- Mutual exclusion is a binary operation: either the lock is free and the resource can be accessed, or the lock is not free and the resource cannot be accessed.
- What if the processing you wish to perform needs to occur with mutual exclusion, but only under _certain conditions_?
- For example, what if we have a number of producer threads adding values to a list, and one consumer thread that needs to wait until, say, the list is full? We want to ensure that the consumer thread executes only when the condition is met.
- Note that this strategy is kind of wasteful. Ideally we wouldn't want our consumer thread to loop but rather our producers to be able to notify the consumer when the list is full.

## [](https://www.omscs-notes.com/operating-systems/threads-and-concurrency/#condition-variables)
