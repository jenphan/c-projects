#include <stdio.h>
#include <ctype.h>

int fibonacci(int number);

int
main()
{
    int number;
    char repeat;

    printf("(´• ω •`) ♡ FIBONACCI GENERATOR (´ε｀ )♡\n");
    do {
        printf("\nPlease enter number of terms to generate: ");
        while (scanf("%d", &number) != 1) {
            printf("Invalid input. Please enter a valid integer. ");
            while (getchar() != '\n');
        }

        int sequence[number];
        for (int i = 0; i < number; i++) {
            sequence[i] = fibonacci(i);
        }

        for (int i = 0; i < number; i++) {
            printf("%d ", sequence[i]);
        }

        printf("\n\nWould you like to generate another sequence (y/n)? ");
        while ((repeat = tolower(getchar())) == '\n');
    } while (repeat == 'y' || repeat == 'Y');

    printf("\nThank you for using Fibonacci Generator. Goodbye!\n");
    return 0;
}

int
fibonacci(int number)
{
    int sequence[number];

    if (number <= 0) {
        return 0;
    }

    if (number == 1) {
        return 1;
    }

    sequence[0] = 0;
    sequence[1] = 1;

    for (int i = 2; i <= number; i++) {
        sequence[i] = sequence[i - 1] + sequence[i - 2];
    }
    return sequence[number];
}