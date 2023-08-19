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
            printf("Invalid input. Please enter a valid integer: ");
            while (getchar() != '\n');
        }

        for (int i = 0; i < number; i++) {
            printf("%d ", fibonacci(i));
        }

        printf("\n\nWould you like to generate another sequence (y/n)? ");
        while ((repeat = tolower(getchar())) == '\n');
    } while (repeat == 'y');

    printf("\nThank you for using Fibonacci Generator. Goodbye!\n");
    return 0;
}

int
fibonacci(int number)
{
    if (number <= 0) {
        return 0;
    } else if (number == 1) {
        return 1;
    }

    int prev = 0;
    int current = 1;
    int result = 0;

    for (int i = 2; i <= number; i++) {
        result = prev + current;
        prev = current;
        current = result;
    }

    return result;
}