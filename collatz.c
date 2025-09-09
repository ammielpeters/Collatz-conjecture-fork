#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void collatz(int n) {
    while (n != 1) {
        printf("%d ", n);
        if (n % 2 == 0)
            n = n / 2;
        else
            n = 3 * n + 1;
    }
    printf("1\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <positive_integer>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    if (n <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    pid_t pid = fork();

    if (pid == 0) { // child
        printf("Child: Collatz sequence for %d: ", n);
        collatz(n);
    } else if (pid > 0) { // parent
        wait(NULL);
        printf("Parent: Child process finished.\n");
    } else {
        perror("fork failed");
        return 1;
    }
    return 0;
}
