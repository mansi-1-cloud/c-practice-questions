#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

int main() {
    FILE *fp;
    char ch, longestWord[100], word[100];
    int n, c = 0;

    fp = fopen("Main.txt", "w");

    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }

    printf("Enter contents into the file (press Ctrl+D or Ctrl+Z and then Enter to finish):\n");
    while ((ch = getchar()) != EOF) {
        fputc(ch, fp);
    }
    fclose(fp);

    fp = fopen("Main.txt", "r");
    if (fp == NULL) {
        printf("Error opening file for reading.\n");
        return 1;
    }

    // Read each word from the file
    while (fscanf(fp, "%s", word) != EOF) {
        // Check if the length of the current word is greater than the length of the longest word found so far
        if (strlen(word) > c) {
            c = strlen(word);
            strcpy(longestWord, word);
        }
    }
    fclose(fp);
    
    printf("Longest word: %s\n", longestWord);

    return 0;
}
