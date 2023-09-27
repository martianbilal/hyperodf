#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) {
    FILE *file;
    char c;
    pid_t pid;

    // Open the file for reading
    file = fopen("helloworld.txt", "r");
    if (file == NULL) {
        perror("Unable to open file!");
        exit(1);
    }
    // Read characters until a space is encountered
    printf("Parent process reading:");
    while ((c = fgetc(file)) != ' ' && c != EOF) {
        putchar(c);
    }
    printf("\n");

    // Create a child process using fork
    pid = fork();

    if (pid < 0) {
        // Error occurred
        perror("Fork failed");
        exit(1);
    } else if (pid == 0) {
        // Child process
        // Read characters until the end of the file
        printf("Child process reading:");
        while ((c = fgetc(file)) != EOF) {
            putchar(c);
        }
        printf("\n");
    } else {
        // Parent process
        printf("In the parent process\n");
        // waitpid(pid, NULL, 0);
        printf("Done with child\n");
    }

    fclose(file);
    return 0;
}
