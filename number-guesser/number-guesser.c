#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int generate_number();
int player_guess();
int play_again();

int
main()
{
    int secret, guess;
    int attempts, points;
    char input[10];
    char again[10];
    
    printf("(´• ω •`) ♡ NUMBER GUESSING GAME (´ε｀ )♡\n");

    do {
        attempts = 0;
        points = 0;
        secret = generate_number();

        while(1) {
            guess = player_guess();
            if (guess == -1) {
                printf("You give up! The secret number was %d.\n", secret);
                break;
            } else {
                attempts++;
                if (secret == guess) {
                    points += 1;
                    fprintf(stdout, "You correctly guessed the secret number %d in %d attempt(s)!\n", secret, attempts);
                    if (!play_again()) {
                        fprintf(stdout, "Thank you for playing! Your score is %d.\n", points);
                        return 0;
                    } else {
                        secret = generate_number();
                        attempts = 0;
                    }
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

int
generate_number()
{
    srand(time(NULL));
    return rand() % 100 + 1;
}

int
player_guess()
{
    int guess;
    char input[10];

    while (1) {
        printf("\nPlease guess a number from 1 - 100 (or 'q' to quit): ");

        fgets(input, sizeof(input), stdin);

        if (strncmp(input, "q", 1) == 0) {
            return -1;
        } else if (sscanf(input, "%d", &guess) != 1) {
            printf("Please enter in a valid integer or 'q' to quit.\n");
        } else if (guess < 1 || guess > 100) {
            printf("Please enter in a number from 1 to 100.\n");
        } else {
            return guess;
        }
    }
}

int
play_again()
{
    char input[10];
    size_t len, i;

    fprintf(stdout, "Do you want to play again (yes/no): ");
    fgets(input, sizeof(input), stdin);
    len = strlen(input);

    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }
    return (strcmp(input, "yes") == 0);
}