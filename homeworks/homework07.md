## Homework 7

### C Exercises

Modify the link below so it points to the `ex07` directory in your
student repository.

[Here is a link to the ex07 directory in my repository](https://github.com/phuston/ExercisesInC/tree/master/exercises/ex07)

### Think OS Chapter 7 reading questions

### Caching

1) What happens if a program writes a new value into the program counter?

    - The flow of execution will jump to another place in the program. 

2) What is the fundamental problem caches are meant to solve?

    - Caches are meant to solve the bottleneck of how expensive it is to transfer data to and from memory. 

3) If cache access time is 1 ns and memory access time is 10 ns, what is the average
access time of a program with hit rate 50%?  How about 90%?

    - With a hit rate of 50%, the average access time is 5.5ns. At 90%, it is 1.9ns.

4) The book gives several examples of programming language features, like loops, that tend 
to improve locality in the access pattern of instructions and/or data.  Can you think of other examples?  
Or counter-examples that might decrease locality?

    - Reading a file sequentially as a stream would also increase locality. A data structure based on a linked list would likely decrease locality (though I think this may have been mentioned in the book) 

5)  If you refactor a program to improve locality, would you say the program is "cache aware"?  Why not?

    - I don't think this necessarily falls into the category of being 'cache aware'. Being cache aware implies deeper knowledge of the underlying hardware it's being run on. I suppose it depends on the nature of the refactor and how deep it goes. 

6) See if you can estimate the cost of a memory cache by comparing the prices of two similar CPUs with 
different cache sizes.

    - A core i5 7400 has a 6MB cache and costs $153 - a core i5 8400 has a 9MB cache and costs $179. That's $26 for 3MB, or ~$8 per MB of cache. 

7) Why are cache policies generally more complex at the bottom of the memory hierarchy?

    - At the bottom of the hierarchy, changes are made more infrequently, so it's possible to develop more complex algorithms that utilize more complicated caching policies. 

8) Can you think of a strategy operating systems could use to avoid thrashing or recover when it occurs?

    - It seems like the OS could just block processes (esp those running in the background) until the system recovers. 



