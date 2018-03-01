## Homework 5

### C Exercises

Modify the link below so it points to the `ex05` directory in your
student repository.

[Here is a link to the ex05 directory in my repository](https://github.com/phuston/ExercisesInC/tree/master/exercises/ex05)

### Think OS Chapter 5 reading questions

**Bits and bytes**

1) Suppose you have the value 128 stored as an unsigned 8-bit number.  What happens if you convert 
it to a 16-bit number and accidentally apply sign extension?

    - If you convert it to a 16-bit number and apply sign extension, you'd end up with 0000000001000000, which is -128

2) Write a C expression that computes the two's complement of 12 using the XOR bitwise operator. 
Try it out and confirm that the result is interpreted as -12.

    - `int comp = 12^-8;`

3) Can you guess why IEEE floating-point uses biased integers to represent the exponent rather than a
sign bit or two's complement?

    - It seems like using a bias would make it far simpler to compare two exponents than in the two's complement scheme - you can simply look at the two numbers and compare them normally with a bias.

4) Following the example in Section 5.3, write the 32-bit binary representation of -13 in single precision 
IEEE floating-point.  What would you get if you accidentally interpreted this value as an integer?

    - -13 = 11000001110100000000000000000000 
    - As an integer, this value is 3251634176 - quite a bit larger! Oopsie! 

5) Write a function that takes a string and converts from lower-case to upper-case by flipping the sixth bit.  
As a challenge, you can make a faster version by reading the string 32 or 64 bits at a time, rather than one
character at a time.  This optimization is made easier if the length of the string is a multiple of 4 or 8 bytes.

```
void upper(char string[]) {
  for (int i = 0; i < strlen(string); i++){
    string[i] = string[i]^32;
  }
  printf("%s\n", string);
}
```



