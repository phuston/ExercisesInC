## Homework 11

### C Exercises

Modify the link below so it points to the `ex11` directory in your
student repository.

[Here is a link to the ex11 directory in my repository](https://github.com/YOUR_GITHUB_USERNAME_HERE/ExercisesInC/tree/master/exercises/ex11)

### Think OS Chapter 11 reading questions

1) Why is is a bad idea to pass a `sem_t` as a parameter?

    - `sem_t` behaves as a structure, so assignment implies copying, and copying could cause unintended/bad behavior. 

2) When you use a Semaphore as a mutex, what should its initial value be?

    - The initial value of a semaphore used as a mutex should be 1 to be unlocked.

3) Can you think of another use for a Semaphore where you might use a different initial value?

    - If you use a semaphore with a process that should have an initial blocked state, it should be 0. 

4) In my solution to the producers-consumers problem using Semaphores,
what does it mean if the value of `queue->spaces` is `3` at some point in time?

    - If `queue->spaces` is 3, this means that there are 3 empty spaces in the queue, and the producer could theoretically add 3 new values to the queue. 

5) What does it mean if `queue->space` is `-3`?

    - This means that somehow push was called 3 times without being blocked. Additionally, 2 spaces were probably overwritten in the process. 

6) Why doesn't `queue_pop` have to use `queue_empty` to check whether the queue is empty?

    - Using semaphores, `queue_pop` can now just check `queue->items` to check how many items there are left.

7) Any problem that can be solved with Semaphores can also be solved with mutexes and condition variables.
How can you prove that that's true?

    - Semaphores can be implemented using just Mutexes and condition variables, which means that the same problems can be solved with just those.

8) What is Property 3?  Hint: see *The Little Book of Semaphores*, 
[Section 4.3](http://greenteapress.com/semaphores/LittleBookOfSemaphores.pdf). 

    - "Property 3: if there are threads waiting on a semaphore when a thread executes signal, then one of the waiting threads has to be woken"




