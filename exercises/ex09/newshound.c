/* Example from Head First C.

Downloaded from https://github.com/twcamper/head-first-c

Modified by Allen Downey.
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

/*
 * Patrick Huston
 * SoftSys Sp18
 */

void error(char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}

void child_code(int i, const char *PYTHON, const char *SCRIPT, char * search_term, char *vars[]) {
    sleep(i);
    int res = execle(PYTHON, PYTHON, SCRIPT, search_term, NULL, vars);
    if (res == -1) {
        error("Unable to execute python script");
    }
    exit(0);
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <search phrase>\n", argv[0]);
        return 1;
    }
    const char *PYTHON = "/usr/bin/python2.7";
    const char *SCRIPT = "rssgossip.py";
    char *feeds[] = {
        "http://www.nytimes.com/services/xml/rss/nyt/Africa.xml",
        "http://www.nytimes.com/services/xml/rss/nyt/Americas.xml",
        "http://www.nytimes.com/services/xml/rss/nyt/MiddleEast.xml",
        "http://www.nytimes.com/services/xml/rss/nyt/Europe.xml",
        "http://www.nytimes.com/services/xml/rss/nyt/AsiaPacific.xml"
    };
    int num_feeds = 5;
    char *search_phrase = argv[1];
    char var[255];
    pid_t pid;
    int status;

    // spawn child processes
    for (int i=0; i<num_feeds; i++) {
        sprintf(var, "RSS_FEED=%s", feeds[i]);
        char *vars[] = {var, NULL};

        printf("Creating child %d \n", i);
        pid = fork();

        if (pid == -1) {
            fprintf(stderr, "Fork failed: %s\n", strerror(errno));
            perror(argv[0]);
            exit(1);
        }
        
        if(!pid){
            child_code(i, PYTHON, SCRIPT, search_phrase, vars);
        }
    }

    // check on child processes
    for (int i=0; i<num_feeds; i++) {
        pid = wait(&status);

        if (pid == -1) {
            fprintf(stderr, "wait failed %s\n", strerror(errno));
            perror(argv[0]);
            exit(1);
        }

        status = WEXITSTATUS(status);
        printf("Child %d exited with error code %d.\n", pid, status);
    }
    exit(0);
}
