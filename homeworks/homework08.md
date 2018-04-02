## Homework 8

### C Exercises

Modify the link below so it points to the `ex08` directory in your
student repository.

[Here is a link to the ex08 directory in my repository](https://github.com/phuston/ExercisesInC/tree/master/exercises/ex08)

### Think OS Chapter 8 reading questions

**Multitasking**

1) What is the kernel's most basic task?

    - The kernel's most basic task is to handle interrupts. 

2) When an interrupt occurs, what part of the hardware state is saved by hardware?

    - The hardware saves the PC and the flag register in memory.

3) What is the difference between an interrupt and a context switch?

    - An interrupt refers to the signal given by a program to the kernel. A context switch is what happens when the kernel decides to switch to another process after receiving an interrupt. 

4) Give an example of an event that might cause a process to move from the blocked to the ready state.

    - An example might be when an operation like disk or network access, which likely won't complete immediately, finishes. At this point, the process is changed from blocked to ready - signaling that the kernel should probably pick it up soon. 

5) Why might a scheduler want to give higher priority to an I/O bound process?

    - A scheduler might give a higher priority to an I/O bound process because it'll likely be in the blocked state for significant periods of time. During these blocked times, it can give priority to CPU-bound processes until the I/O-bound process moves back to the ready state. 

When I make French toast, I usually make a batch of 12 slices.  But my griddle only has room for 8 slices. 
Each piece of toast has to cook for 5 minutes on each side.  How can I schedule 12 slices onto 8 "cores"
to minimize the elapsed time to cook all 12 slices?  (Note: this question is not hypothetical; 
this is really how I make French toast.)

    - Put 8 slices on, cook one side.
    - Flip 4 of these original 8, put 4 new uncooked in place of other original 4
    - Remove fully cooked 4, flip other 4 on griddle, put 4 removed back on griddle
    - Cook for 5 minutes on final 8 sides
    
    Profit, 15 minutes later.



