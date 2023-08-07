#include <stdio.h>

void print_menu();
int calculate_result(int op, int num1, int num2);

int
main()
{
    int op, num1, num2, result;
    while(1) {
        print_menu();
        printf("Please enter the operator option: ");
        if (scanf("%d", &op) != 1 || (op < 1 || op > 5)) {
            fprintf(stderr, "Invalid operator choice\n");
            printf("\n");
            while (getchar() != '\n');
            continue;
        } else {
            if (op == 5) {
                printf("Exiting calculator program.");
                break;
            }
        }

        printf("Please enter the first number: ");
        if (scanf("%d", &num1) != 1) {
            fprintf(stderr, "Invalid input for first number\n");
            printf("\n");
            while (getchar() != '\n');
            continue;
        }

        printf("Please enter the second number: ");
        if (scanf("%d", &num2) != 1) {
            fprintf(stderr, "Invalid input for the second number\n");
            printf("\n");
            while (getchar() != '\n');
            continue;
        }

        result = calculate_result(op, num1, num2);  
        printf("Result: %d\n\n", result);     
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
calculate_result(int op, int num1, int num2)
{
    if (op == 1) {
        return num1 + num2;
    } else if (op == 2) {
        return num1 - num2;
    } else if (op == 3) {
        return num1 * num2;
    } else if (op == 4) {
        return num1 / num2;
    }
    return -1;
}