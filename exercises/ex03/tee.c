/*
 * tee.c
 *
 * Implements the 'tee' linux command-line tool, which reads from
 * standard input and writes to standard output and files.
 *
 * Author - Patrick Huston
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

#define BUFSIZE 100

static int append_mode = 0;

/* 
 * When writing tee, I found that I was slowed down when I kept
 * on thinking of more and more ways the program could be broken 
 * by all sorts of errors and issues in my logic that could be abused.
 * What I did to get through this was just getting a basic implementation
 * working, and then incrementally building up more and more error
 * checking. Next time, I'd probably compile and test more as I build
 * up the logic little by little. I didn't compile until I had nearly
 * the entire tool written, and had a lot of errors to work through.
 *
 * Looking at the other implementations, their code is a lot more
 * concise and clear than mine is. I think if I thought about my code
 * more, I could probably pare it down and make it more elegant, but
 * as it stands right now, it's not especially well-designed. These
 * 'professional' implementations also seem to cover a lot more edge cases
 * than my code does, which is something that I started to think about
 * but then ended up deciding not to work on.
 */

/*
 * parse_args
 *
 * Takes in command-line arguments passed in, sets
 * appropriate flags, and returns success
 */
int parse_args(int argc, char *argv[]) {
    char ch;
    while ((ch = getopt(argc, argv, "a")) != -1) {
        switch (ch) {
        case 'a':
            append_mode = 1;
            break;
        case '?':
            fprintf(stderr, "ERROR: unknown option");
            return 1;
        default:
            abort();
            break;
        }
    }
    return 0;
}

/* cleanup_files
 *
 * Takes in a list of files and closes them all
 */ 
void cleanup_files(int num_files, FILE *files[]) {
    for (int i=0; i<num_files; i++) {
        fclose(files[i]);
    }
}


int main(int argc, char *argv[]) {
    char buf[100];
    size_t len;
    char *file_mode;
    int i;
    FILE *files[20];
    int num_files;
    char buffer[BUFSIZE];

    // Catch and forward errors in arg parse
    if (parse_args(argc, argv)) {
        return 1;
    }

    file_mode = (append_mode ? "a" : "w");

    num_files = argc - optind;
    printf("%d", num_files);

    if(num_files > 0) {
        // Go through file args, open for writing or append
        for (i=optind; i<argc; i++) {
            FILE *pFile = fopen(argv[i], file_mode);
            if (pFile == NULL) {
                fprintf(stderr, "Unable to open file %s", argv[i]);
                cleanup_files(num_files, files);
                return 0;
            }

            files[i-optind] = pFile;
        }
    }

    while (NULL != fgets(buffer, BUFSIZE, stdin)) {
        for(i=0; i<num_files; i++) {
            fprintf(files[i], "%s", buffer);
        }
        printf("%s", buffer);
    }

    cleanup_files(num_files, files);
    return 0;
}
