/*
 * adder.c
 *
 * This program prompts users to enter integers line-by-line
 * until the EOF character Ctrl-D is entered. The sum of all
 * the integers is then displayed to the user.
 *
 * Patrick Huston
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define BUFFER_SIZE 10
#define ARRAY_SIZE 8

int addIntegers(int integers[], int num_elements);
int get_input(char buffer[]); 


int main() {
    printf("Welcome to adder! Start entering numbers.\n");

    int number_array[ARRAY_SIZE];
    char buffer_inp[BUFFER_SIZE];
    int input_count = 0;
    long input_num;
    char * temp;

    while(input_count <= ARRAY_SIZE) {
        if(get_input(buffer_inp) != 0) {
            break;
        }

        if (input_count == ARRAY_SIZE) {
            printf("Max number of inputs received. Auto-summing inputs now.");
            break;
        }

        // Decided to use strtol - couldn't figure how to check error with atoi
        input_num = strtol(buffer_inp, &temp, 10);
        if (buffer_inp == temp) {
            printf("ERROR: Could not parse input as number\n");
            continue;
        }
        else if (input_num < INT_MIN || input_num > INT_MAX) {
            printf("ERROR: Number overflowed or underflowed int\n");
            continue;
        }
        else {
            number_array[input_count] = (int) input_num;
            input_count++;
        }
    }
    int sum = addIntegers(number_array, input_count);
    printf("Adding...\n");
    printf("Total: %d\n", sum);
    return 0;
}

/*
 * Fills up input buffer character by character and builds up char array
 * Checks for buffer overflow and newline as it goes
 *
 * buffer - character buffer from stdin
 */
int get_input(char buffer[]) {
    // Note: talked with Kai about his implementation not using fgets()
    int buffer_pos = 0;
    char inp = 0;
    while (inp != EOF) {
        inp = getchar();
        // Check if newline has been entered 
        if (inp == '\n') {
            buffer[buffer_pos + 1] = '\0';
            return 0;
        }
        // Check for buffer overflow
        // Still having an error where the buffer overflows multiple times
        if (buffer_pos > BUFFER_SIZE) {
            printf("ERROR: Buffer overflow \n");
            return 0;
        }
        buffer[buffer_pos] = inp;
        buffer_pos++;
    }
    // EOF entered - sum
    return 1;
}

/*
 * Adds up all the integers and returns the sum
 *
 * integers - the array of integers
 * num_elements - the number of elements in the array
 *
 * sum - the sum of the elements
 */
int addIntegers(int integers[], int num_elements) {
    printf("CALLING ADD INTEGERS\n");
    int i, sum = 0;
    for (i=0; i<num_elements; i++) {
        printf("Found %d\n", integers[i]);
        sum = sum + integers[i];
    }
    return sum;
}

