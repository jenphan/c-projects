#include <stdio.h>

void print_menu();
int calculate_result(int op, float num1, float num2);

int
main()
{
    int op;
    float num1, num2, result;
    while(1) {
        print_menu();
        printf("Please enter the operator option: ");
        if (scanf("%d", &op) != 1 || (op < 1 || op > 5)) {
            fprintf(stderr, "Please select a valid operation (1 - 5)\n");
            printf("\n");
            while (getchar() != '\n');
            continue;
        } else {
            if (op == 5) {
                printf("Exiting calculator program.\n");
                break;
            }
        }

        printf("Please enter the first number: ");
        if (scanf("%f", &num1) != 1) {
            fprintf(stderr, "Invalid input for first number\n");
            printf("\n");
            while (getchar() != '\n');
            continue;
        }

        printf("Please enter the second number: ");
        if (scanf("%f", &num2) != 1) {
            fprintf(stderr, "Invalid input for the second number\n");
            printf("\n");
            while (getchar() != '\n');
            continue;
        } else if (num2 == 0 && op == 4) {
            fprintf(stderr, "Cannot divide by zero\n");
            printf("\n");
            while (getchar() != '\n');
            continue;
        }

        result = calculate_result(op, num1, num2);  
        printf("Result: %.2f\n\n", result);     
    }
    return 0;
}

void
print_menu()
{
    printf("(´• ω •`) ♡ SIMPLE CALCULATOR MENU (´ε｀ )♡\n"
            "1. Addition\n"
            "2. Subtraction\n"
            "3. Multiplication\n"
            "4. Division\n"
            "5. Exit\n");
}

int
calculate_result(int op, float num1, float num2)
{
    float result;
    if (op == 1) {
        result = num1 + num2;
    } else if (op == 2) {
        result = num1 - num2;
    } else if (op == 3) {
        result = num1 * num2;
    } else if (op == 4) {
        result = num1 / num2;
    }
    return result;
}