## Homework 2.5

### C Exercises

Modify the link below so it points to the `ex02.5` directory in your
student repository.

[Here is a link to the ex02.5 directory in my repository](https://github.com/phuston/ExercisesInC/tree/master/exercises/ex02.5)

### Think OS Chapter 3 reading questions

### Virtual memory

1) The Georgian alphabet has 33 letters.  How many bit are needed to specify a letter?

    - 2^6 = 64 - 6 bits are needed. 5 bits would not be sufficient. 

2) In the UTF-16 character encoding, the binary representation of a character can take up to 32 bits.  
Ignoring the details of the encoding scheme, how many different characters can be represented?

    - 2^32 = 4,294,967,296 characters could be represented. 

3) What is the difference between "memory" and "storage" as defined in *Think OS*?

    - Memory (often known as RAM) refers to volatile storage used for running processes. Storage (HDDs and SSDs) refers to non-volatile persistent memory, and is often much larger than "memory"

4) What is the difference between a GiB and a GB?  What is the percentage difference in their sizes?

    - A GiB (gibibyte, used more commonly for memory) is 2^30 bytes = 1,073,741,824 bytes. A GB (gigabyte, used more commonly when referring to storage) is 10^9 bytes = 1,000,000,000 bytes. This ends up being a 7.11196% percent difference. 

5) How does the virtual memory system help isolate processes from each other?

    - Virtual memory helps isolate processes from each other because a process cannot access data belonging to another process - there is no virtual address it can generate that maps to a physical memory location allocated to another running process.

6) Why do you think the stack and the heap are usually located at opposite ends of the address space?

    - The stack and heap are probably located at opposite ends so they can grow towards each other - allocating memory in the same direction makes incrementing easier, and you always know where the next open address is. Due to this, it ensures that all the data is localized.

7) What Python data structure would you use to represent a sparse array?

    - I could imagine implementing a sparse aray in Python using a dictionary that maps from non-null locations to their values. Every empty location would just not be represented.

8) What is a context switch?

    - A context switch happens when an OS interrupts a running process, saves its state, and then runs another process.
