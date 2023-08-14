#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int
main()
{
    int secret, guess;
    int attempts = 0;
    char input[10];
    
    srand(time(NULL));
    secret = rand() % 100 + 1;
    printf("(´• ω •`) ♡ NUMBER GUESSING GAME (´ε｀ )♡\n");
    
    while(1) {
        printf("\nPlease guess a number from 1 - 100 (or q to quit): ");
        fgets(input, sizeof(input), stdin);
        if (strncmp(input, "q", 1) == 0) {
            printf("You give up! The secret number was %d.\n", secret);
            break;
        }
        if (sscanf(input, "%d", &guess) != 1) {
            printf("Please enter in a valid integer.\n");
        } else if (guess < 1 || guess > 100) {
            printf("Please enter in a number from 1 to 100.\n");
        } else {
            attempts += 1;
            if (secret == guess) {
                fprintf(stdout, "You correctly guessed the secret number %d in %d attempt(s)!\n", secret, attempts);
                break;
            } else if (secret > guess) {
                fprintf(stdout, "The secret number is HIGHER than your guess %d.\n", guess);
            } else {
                fprintf(stdout, "The secret number is LOWER than your guess %d.\n", guess);
            }
        }
    }
    return 0;
}