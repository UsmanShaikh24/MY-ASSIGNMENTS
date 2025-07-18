// Count the Number of Vowels in a Given Sentence Using vfork()

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>

int count_vowels(const char *sentence) {
    int count = 0;
    for (int i = 0; sentence[i] != '\0'; i++) {
        char ch = tolower(sentence[i]);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
    }
    return count;
}

int main() {
    char sentence[100];

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    sentence[strcspn(sentence, "\n")] = '\0';  // Remove trailing newline

    pid_t pid = vfork();

    if (pid < 0) {
        perror("vfork failed");
        exit(1);
    } else if (pid == 0) {
        // Child process: Count vowels
        int vowels = count_vowels(sentence);
        printf("Child Process - Number of Vowels: %d\n", vowels);
        _exit(0);
    } else {
        // Parent process
        printf("Parent Process - Original Sentence: %s\n", sentence);
    }

    return 0;
}
