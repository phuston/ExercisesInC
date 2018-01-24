#include <stdio.h>
#include <stdlib.h>

/*
 * Cards.c - runs a card game and counts cards
 */

/*
 * Updates the card counting value based on the current value of card
 *
 * curr_count: represents the current card counting value
 * value: the value of the card turned over
 */
int update_count(int curr_count, int value) {
    if ((value > 2) && (value < 7)) {
        return curr_count + 1;
    } else if (value == 10) {
        return curr_count - 1;
    } else {
        return curr_count;
    }
}

/*
 * Returns the value of the card based on its name
 * 
 * If the card is not valid, the function will return -1 to flag this case
 *
 * card_name: name of the card
 */
int get_card_value(char card_name[3]) {
    int val = 0;
    switch(card_name[0]) {
    case 'K':
    case 'Q':
    case 'J':
        val = 10;
        break;
    case 'A':
        val = 11;
        break;
    case 'X':
        return -1;
    default:
        val = atoi(card_name);;
        if ((val < 1) || (val > 10)) {
            puts("I don't understand that value!");
            return -1;
        } 
    }
    return val;
}

/*
 * Runs the poker game
 */
int main()
{
    char card_name[3];
    int count = 0;
    do {
        puts("Enter the card name: ");
        scanf("%2s", card_name);
        
        /* Compute card value */
        int val = get_card_value(card_name);
        if (val == -1) {
            continue;
        }

        /* Update count accordingly */
        count = update_count(count, val);

        printf("Current count: %i\n", count);
    } while (card_name[0] != 'X');
    return 0;
}

