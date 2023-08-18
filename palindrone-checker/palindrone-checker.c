#include <stdio.h>
#include <string.h>

int
main()
{
    char word[50], reverse[50];
    int length, i;

    printf("(´• ω •`) ♡ PALINDRONE CHECKER (´ε｀ )♡\n");
    printf("Please enter a single word to check: ");

    scanf("%s", word);
    length = strlen(word);

    for (i = 0; i < length; i++) {
        reverse[i] = word[length - 1 - i];
    }
    reverse[length] = '\0';

   if (strcmp(word, reverse) == 0) {
       printf("\n%s IS a palindrone! :)\n", word);
   } else {
       printf("\n%s IS NOT a palindrone :(\n", word);
   }
   
   return 0;
}