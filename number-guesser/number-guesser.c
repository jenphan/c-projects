#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int
main()
{
    int secret, guess;
    int attempts, points;
    char input[10];
    char again[10];
    
    srand(time(NULL));
    printf("(´• ω •`) ♡ NUMBER GUESSING GAME (´ε｀ )♡\n");

    do {
        attempts = 0;
        points = 0;
        secret = rand() % 100 + 1;

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
                    points += 1;
                    fprintf(stdout, "You correctly guessed the secret number %d in %d attempt(s)!\n", secret, attempts);
                    fprintf(stdout, "DO you want to play again (yes/no): ");
                    fgets(again, sizeof(again), stdin);
                    again[strcspn(again, "\n")] = '\0';

                    if (strcmp(again, "no") == 0) {
                        fprintf(stdout, "Thank you for playing! Your score is %d.\n", points);
                        return 0;
                    } else if (strcmp(again, "yes") != 0) {
                        fprintf(stdout, "Invalid input. Playing another game.\n");
                    }

                    secret = rand() % 100 + 1;
                    attempts = 0;
                } else if (secret > guess) {
                    fprintf(stdout, "The secret number is HIGHER than your guess %d.\n", guess);
                } else {
                    fprintf(stdout, "The secret number is LOWER than your guess %d.\n", guess);
                }
            }
        } 
    } while (1);
    return 0;
}