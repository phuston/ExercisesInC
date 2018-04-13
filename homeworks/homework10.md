## Homework 10

### C Exercises

Modify the link below so it points to the `ex12` directory in your
student repository.  That's right, Homework 10 is to do Exercise 12.

[Here is a link to the ex12 directory in my repository](https://github.com/YOUR_GITHUB_USERNAME_HERE/ExercisesInC/tree/master/exercises/ex12)

### Think OS Chapter 10 reading questions

1) What does it mean to say that a data structure is thread safe?

    - A thread safe data structure can be accessed by multiple threads safely without causing unexpected (or just wrong) behavior.

2) In the circular buffer implementation of a queue, why is the maximum number of elements in the queue `n-1`,
if `n` is the size of the array?

    - If it weren't, you could store a value at `n`, which means that `next_in == next_out`, which would imply that the queue is empty. 

3) If there is no mutex to protect the queue, give an example of a sequence of steps that could leave
the queue in an inconsistent state.

    - Producer puts an element on the queue, Consumer A wakes up and starts processing, but gets interrupted. Consumer B sees that there's an element on the queue, does work, finishes, Consumer A is resumed and does the same piece of work again. 

4) When a thread calls `cond_wait`, why does it have to unlock the mutex before blocking?

    - If it didn't, no other threads would be able to alter the data structure, which means the condition would never change.

5) When a thread returns from `cond_wait`, what do we know is definitely true?  What do we think is probably true?

    - We definitely know that the mutex is locked and the condition being waited on may be true. We need to check again because there may have been an intercepted message where another thread did the work. 

6) What happens if you signal a condition variable when there are no waiting threads?

    - Nothing happens

7) Do you have to lock the mutex to signal a condition variable?

    - No, you don't *have* to lock the mutex to signal a condition variable. The threads waiting would logically be blocked anyway and shouldn't be able to do anything to the data structure. This could potentially be an issue if there are multiple producers, however.

8) Does the condition have to be true when you signal a condition variable?

    - Not necessarily - it would be bad practice to trigger when you know it's definitely not true, but the thread waiting should be able to handle this case anyway - the condition should always be checked no matter what. 




