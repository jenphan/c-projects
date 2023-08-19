#include <stdio.h>

int fibonacci(int number);

int
main()
{
    int number;
    if (scanf("%d", &number) != 1) {
        printf("Invalid input. Please enter a valid integer.\n");
    }

    int sequence[number];
    for (int i = 0; i < number; i++) {
        sequence[i] = fibonacci(i);
    }

    for (int i = 0; i < number; i++) {
        printf("%d ", sequence[i]);
    }
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