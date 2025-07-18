#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

int main() {
    pid_t pid;
    int fd[2];         // Array for pipe file descriptors
    char buffer[100];  // Buffer to read data
    char data[] = "Hello, this is a message from the producer.";  // Producer's message

    // Create pipe
    if (pipe(fd) == -1) {
        perror("Pipe creation error");
        exit(EXIT_FAILURE);
    }

    // Create child process
    pid = fork();
    if (pid == -1) {
        perror("Fork error");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { // Child process (Producer)
        close(fd[0]); // Close read end of the pipe
        printf("Child Process (Producer): Writing to pipe.\n");
        if (write(fd[1], data, strlen(data)) == -1) {
            perror("Write error");
            exit(EXIT_FAILURE);
        }
        close(fd[1]); // Close write end after writing
    } else { // Parent process (Consumer)
        close(fd[1]); // Close write end of the pipe
        printf("Parent Process (Consumer): Reading from pipe.\n");
        if (read(fd[0], buffer, sizeof(buffer)) == -1) {
            perror("Read error");
            exit(EXIT_FAILURE);
        }
        printf("Parent Process (Consumer): Received message: %s\n", buffer);
        close(fd[0]); // Close read end after reading
    }

    return 0;
}
