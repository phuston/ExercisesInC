## Homework 1

### C Exercises

[Here is a link to the ex01 directory in my repository](https://github.com/phuston/ExercisesInC/tree/master/exercises/ex01)

### Think OS Chapter 1 reading questions

1) Give an example of a feature common in interpreted languages that is rare in compiled languages.

Dynamic typing is more common in interpreted languages, whereas static typing is more common in compiled languages.

2) Name two advantages of static typing over dynamic typing.

- You can use a compiler to prevent many potential runtime errors due to mishandling types
- Static typing allows the code to be compiled and thus it can run faster without having to check types at runtime

3) Give an example of a static semantic error.

An example could be a type incompatability - e.g. `int x = "hello world";`

4) What are two reasons you might want to turn off code optimization?

- The optimization might behave slightly differently in specific cases than the version written
- The optimization might hide or obfuscate the source of errors in your code, making it more difficult to debug

5) When you run `gcc` with `-S`, why might the results look different on different computers?

The `-S` flag tells the compiler to generate assembly code, and depending on the architecture of your processor, the instruction set (and thus the output) may end up being slightly different.

6) If you spell a variable name wrong, or if you spell a function name wrong, the error messages 
you get might look very different.  Why?

If you spell a variable or function name wrong, you will get an error message from the linker as it trys to find something that isn't defined in any of the standard libraries.

7) What is a segmentation fault?

A segmentation fault occurs when you try to read or write an incorrect location in memory. 
