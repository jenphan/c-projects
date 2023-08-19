#include <stdio.h>

long long get_factorial(int num);

int
main()
{
    int num, i;
    long long answer;
    char again;

    printf("(´• ω •`) ♡ FACTORIAL CALCULATOR (´ε｀ )♡\n");
    do {
        answer = 1;

        printf("\nPlease enter a positive integer: ");
        if (scanf("%d", &num) != 1) {
            printf("Invalid input. Please enter a valid number.\n");
            while (getchar() != '\n');
            continue;
        }

        if (num < 0) {
            printf("Factorial is not defined for negative numbers.\n");
        } else if (num > 20) {
            printf("This number's factorial would be too large to display.\n");
        } else {
            answer = get_factorial(num);
        }
        printf("\nCalculate another factorial (y/n)? ");
        while ((again = getchar()) == '\n');
    } while (again == 'y' || again == 'Y');
    printf("\nThank you for using the Factorial Calculator. Goodbye!\n");
    return 0;
}

long long
get_factorial(int num)
{
    int i;
    long long answer = 1;
    for (i = 1; i <= num; i++) {
            answer *= i;
        }
    printf("%d! = %lld\n", num, answer);
    return answer;
}