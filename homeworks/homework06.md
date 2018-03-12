## Homework 6

### C Exercises

Modify the link below so it points to the `ex06` directory in your
student repository.

[Here is a link to the ex06 directory in my repository](https://github.com/phuston/ExercisesInC/tree/master/exercises/ex06)

### Think OS Chapter 6 reading questions

**Memory management**

1) Which memory management functions would you expect to take constant time?
Which ones take time proportional to the size of the allocated chunk?

        - I would expect `malloc` and `free` to generally be in constant time - malloc might not always be if there aren't enough free blocks. `calloc` and `realloc` take time proportional to the size of the allocated chunk.

2) For each of the following memory errors, give an example of something that might go wrong:

a) Reading from unallocated memory.
        
        - Ideally, you'd get a segfault. But there is still a chance that you read whatever random values might have been there before. 

b) Writing to unallocated memory.
        
        - You run the risk of overwriting internal data structures for `free` and `malloc` that could cause unintended and very serious issues later in the program execution. 

c) Reading from a freed chunk.
        
        - If reading from a freed chunk, you'd either end up with a segfault or unintentionally reading whatever values were there before. 

d) Writing to a freed chunk.
        
        - Similar to unallocated memory, you could easily end up overwriting some of the data structures internal to malloc that could cause really nasty and difficult to trace side effects later on. 

e) Failing to free a chunk that is no longer needed.
        
        - This is what's known as a memory leak! The total memory used could end up increasing indefinitely - causing either the system to run out of physical memory or the program to run out of virtual memory. Calls to `malloc` would eventually return `NULL`, causing errors down the line. 

3) Run

```
    ps aux --sort rss
```

to see a list of processes sorted by RSS, which is "resident set size", the amount of physical 
memory a process has.  Which processes are using the most memory?

4) What's wrong with allocating a large number of small chunks?  What can you do to mitigate the problem?

If you want to know more about how malloc works, read 
[Doug Lea's paper about dlmalloc](http://gee.cs.oswego.edu/dl/html/malloc.html)
