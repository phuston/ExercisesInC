## Homework 2

### C Exercises

Modify the link below so it points to the `ex02` directory in your
student repository.

[Here is a link to the ex02 directory in my repository](https://github.com/YOUR_GITHUB_USERNAME_HERE/ExercisesInC/tree/master/exercises/ex02)

### Think OS Chapter 1 reading questions

For each of the reading questions below, write answers in the form of
a clear, concise, complete sentence or two.

1. Give a real-world example of virtualization (ideally not one of 
the ones in the book).  What is abstractly true about the system that
is not literally true about the implementation?

    - Another example of virtualization is the US Postal Service. As a user, we're exposed to the abstraction of addresses and postal codes, but we don't have to worry about the underlying sorting and shipment infrastructure. In the abstract system, we only care about putting stamps on with the right value and addressing them to the correct location.

2. What is the difference between a program and a process?

    - A process is an abstraction that isolates each running program, and includes objects such as the program text, data associated with the program, the state of i/o operations, and the hardware state of the program. The program is but one part of a process, and a process can theoretically run multiple programs. 

3. What is the primary purpose of the process abstraction?

    - The process abstraction serves the purpose of isolation so the programmer doesn't have to think about the potentially complex and cumbersome interactions between their code and everything else that's happening concurrently on the computer. 

4. What illusion does the process abstraction create?

    - The process abstraction creates the illusion that each running program is isolated and has its own access controls to the underlying hardware and input/output operations.

5. What is the kernel?

    - The kernel is the core part of the operating system that's responsible for core functionality like creating threads.

6. What is a daemon?

    - A daemon is a type of process that runs in the background and provides operating system services. 
