/* 
 * word_count reads in a specified file and prints out 
 * individual frequencies for how often each word appears
 *
 * Author: Patrick Huston
 * Software Systems SP18
 * Olin College of Engineering
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#include <glib.h>
#include <ctype.h>

#define STATUS_OK 0
#define STATUS_ERR 1
#define NUM_MATCHES 1
#define L_CASE 32

char* read_line(FILE *file, int *status) {
    char *line = NULL;
	size_t len = 0;
	ssize_t read;
	if((read = getline(&line, &len, file)) == -1) {
		*status = STATUS_ERR;
	} else {
		*status = STATUS_OK;
	}
	return line;

}

/*
 * Tokenizes each line, and adds the word to the
 * frequency hashtable
 */
void split_words(char *str, GHashTable *hash) {
    char* word = strtok(str, " ");
    gpointer value = NULL;
    int *i;
    while(word != NULL) {
        value = g_hash_table_lookup(hash, word);
        if(value != NULL) {
            // Value is present, increment
            i = (int*) value;
            *i = *i + 1;
        } else {
            // Value not present, add to hashtable
            i = malloc(sizeof(int));
            *i = 1;
        }

        value = i;
        g_hash_table_insert(hash, word, value);
        word = strtok(NULL, " ");
    }
}

/* 
 * Takes in a pointer to a line, iterates through
 * and removes all punctuation and lowercases string
 */
void clean_line(char *line, char *cleaned_line) {
    for (; *line; ++line)
        if (!ispunct((unsigned char) *line))
            *cleaned_line++ = tolower((unsigned char) *line);
    *cleaned_line = 0;
}

/*
 * Reads words in from a file, cleans words, and splits
 * Results are stored in the GHashTable passed in as a param
 */
void read_words(FILE *file, int *status, GHashTable *hash) {
    char* line = NULL;
    line = read_line(file, status);
    clean_line(line, line);
    split_words(line, hash);
}

/*
 * Prints frequencies of word from input hashtable
 */ 
void print_freq(GHashTable *hash) {
    GHashTableIter iter;
	gpointer key, value; 
	g_hash_table_iter_init (&iter, hash);
	char* word;
	int frequency;
	while (g_hash_table_iter_next (&iter, &key, &value)) {
		word = (char*) key;
		frequency = *((int*) value);
		printf("%s occurs %d times\n", word, frequency);
	}
}

int main() {
    int status = STATUS_OK;
    FILE *pride = fopen("./pride.txt", "rb");    
    GHashTable* freq = g_hash_table_new(g_str_hash, g_str_equal);

    while(status == STATUS_OK) {
		read_words(pride, &status, freq);
	}

    print_freq(freq);

    return 0;
}
