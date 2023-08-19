#include <stdio.h>

int
main()
{
    int num, i;
    long long answer = 1;

    printf("(´• ω •`) ♡ FACTORIAL CALCULATOR (´ε｀ )♡\n");
    printf("\nPlease enter a number: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else if (num > 20) {
        printf("This factorial would be too large to display.\n");
    } else {
        for (i = 1; i <= num; i++) {
            answer *= i;
        }
        printf("%d! = %lld\n", num, answer);
    }
    return 0;
}