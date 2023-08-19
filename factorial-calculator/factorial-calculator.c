#include <stdio.h>
#include <ctype.h>

int
main()
{
    int number;
    long long factorial;
    char repeat;

    printf("(´• ω •`) ♡ FACTORIAL CALCULATOR (´ε｀ )♡\n");
    do {
        factorial = 1;

        printf("\nPlease enter a positive number: ");
        if (scanf("%d", &number) != 1) {
            printf("Invalid input. Please enter a valid number.\n");
            while (getchar() != '\n');
            continue;
        }

        if (number < 0) {
            printf("Factorial is not defined for negative numbers.\n");
        } else if (number > 20) {
            printf("Factorial of %d is too large to display.\n", number);
        } else {
            for (int i = 1; i <= number; i++) {
                factorial *= i;
            }
            printf("%d! = %lld\n", number, factorial);
        }

        printf("\nDo you want to calculate another factorial (y/n)? ");
        while ((repeat = tolower(getchar())) == '\n');
    } while (repeat == 'y' || repeat == 'Y');

    printf("\nThank you for using the Factorial Calculator. Goodbye!\n");
    return 0;
}