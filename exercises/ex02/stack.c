/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int *foo() {
    int i;
    int array[SIZE];

    printf("%p\n", array); // Array initialized in local stack

    for (i=0; i<SIZE; i++) {
        array[i] = 42;
    }

    return array; // Returns a pointer to this local array
}

void bar() {
    int i;
    int array[SIZE]; // Creates another array in the stack - overwrites other arr

    printf("Bar %p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = i;
    }
}

int main()
{
    int i;
    int *array = foo(); // Just a pointer to the stack, which is volatile
    bar();

    for (i=0; i<SIZE; i++) {
        // Reads from the stack, which will have been written to since foo() ran
        // Where a seg fault could potentially occur
        printf("%d\n", array[i]);
    }

    return 0;
}
