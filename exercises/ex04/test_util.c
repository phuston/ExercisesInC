#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "util.h"
#include "minunit.h"

int tests_run = 0;

static char *test1() {
	char *res = icmpcode_v4(0);
	char *message = "test1 failed: (\"icmpcode_v4\", \"0\") should return \"network unreachable\"";
	mu_assert(message, strcmp(res, "network unreachable") == 0);
	return NULL;
}

static char *test2() {
	char *res = icmpcode_v4(1);
	char *message = "test2 failed: (\"icmpcode_v4\", \"1\") should return \"host unreachable\"";
	mu_assert(message, strcmp(res, "host unreachable") == 0);
	return NULL;
}

static char *test3() {
	char *res = icmpcode_v4(16);
	char *message = "test2 failed: (\"icmpcode_v4\", \"16\") should return \"[unknown code]\"";
	mu_assert(message, strcmp(res, "[unknown code]") == 0);
	return NULL;
}

static char *all_tests() {
	mu_run_test(test1);
	mu_run_test(test2);
	mu_run_test(test3);
	return NULL;
}

int main() {
    char *result = all_tests();
    if (result != NULL) {
        printf("%s\n", result);
    } else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}