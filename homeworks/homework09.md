## Homework 9

### C Exercises

Modify the link below so it points to the `ex09` directory in your
student repository.

[Here is a link to the ex09 directory in my repository](https://github.com/phuston/ExercisesInC/tree/master/exercises/ex09)

### Think OS Chapter 9 reading questions

1) Why does each thread have its own stack?

    - Each thread has its own stack so that they don't interfere with each other when calling functions simultaneously.

2) What does the gcc flag `-lpthread` do?

    - This flag compiles the Pthread library.

3) What does the argument of `pthread_exit` do?

    - The argument to `pthread_exit` is the value passed from the child thread to the parent thread it's joining with. 

4) Normally the same thread that created a thread also waits to join it.
What happens if another thread tries to join a thread it did not create?

    - This should be fine. Any thread should be able to join another.

5) What goes wrong if several threads try to increment a shared integer at the same time?

    - The output might be fraught with synchronization errors - and the output value may not be as expected. Because values are written and read at unknown times, the behavior can easily be non-deterministic.

6) What does it mean to "lock a mutex"?

    - It means to prevent access by other threads accessing the object. The mutex will only be available to other threads when the thread unlocks the mutex.

