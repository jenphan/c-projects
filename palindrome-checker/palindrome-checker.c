#include <stdio.h>
#include <string.h>

int
main()
{
    char word[50], reverse[50], again;
    int length, i;

    printf("(´• ω •`) ♡ PALINDROME CHECKER (´ε｀ )♡\n");
    do {
        printf("\nPlease enter a single word to check: ");
        scanf("%s", word);
        length = strlen(word);
        while (getchar() != '\n');

        for (i = 0; i < length; i++) {
            reverse[i] = word[length - 1 - i];
        }
        reverse[length] = '\0';

        if (strcmp(word, reverse) == 0) {
            printf("%s IS a palindrone! :)\n", word);
        } else {
            printf("%s IS NOT a palindrone :(\n", word);
        }

        printf("\nWould you like to check another word (y/n)? ");
        while ((again = getchar()) == '\n');
    } while (again == 'y' || again == 'Y');
    printf("\nThank you for using the palindrome checker. Goodbye!\n");
   return 0;
}