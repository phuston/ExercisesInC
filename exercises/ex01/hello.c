#include <stdio.h>

int main() {
    int x = 5;
    int y = x + 1;
    printf("%d",x);
    return 0;
}

/*
 * Experiment 1: 
 *
 * These lines in the normal assembly output seem to be responsible -
 * movl	$0, -4(%rbp)
 * movl	$6, -8(%rbp)
 */

/*
 * Experiment 2: 
 *
 * When the optimization flag is used, the lines above disappear.
 * Instead, it looks the compiler uses a different print function, cutting out
 * redundancies in setting up the variables, and not storing x since it's
 * not ever used.
 */

/* Experiment 3:
 * 
 * It looks like it calls a different print function, takes fewer movl actions,
 * and sets up x differently using XOR and ADD
 */

/*
 * Experiment 4:
 *
 * In the optimized version, several of the move operations from the non-optimized
 * version get collected into single functions. E.g. it just assigns y to 6 because x
 * isn't actually used.
 */
