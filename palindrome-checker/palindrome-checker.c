#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50

void check_palindrome(const char* word);

int
main()
{
    char word[MAX_WORD_LENGTH], again;

    printf("(´• ω •`) ♡ PALINDROME CHECKER (´ε｀ )♡\n");
    do {
        printf("\nPlease enter a single word to check: ");
        scanf("%s", word);
        while (getchar() != '\n');

        check_palindrome(word);

        printf("\nWould you like to check another word (y/n)? ");
        while ((again = getchar()) == '\n');
    } while (tolower(again) == 'y');

    printf("\nThank you for using the palindrome checker. Goodbye!\n");
    return 0;
}

void
check_palindrome(const char *word)
{
    char reversed[MAX_WORD_LENGTH];
    int length, i;

    length = strlen(word);

    for (i = 0; i < length; i++) {
        reversed[i] = word[length - 1 - i];
    }

    reversed[length] = '\0';

    if (strcasecmp(word, reversed) == 0) {
        printf("%s IS a palindrome! :)\n", word);
    } else {
        printf("%s IS NOT a palindrome :(\n", word);
    }
}