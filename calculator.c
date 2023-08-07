#include <stdio.h>
#include <stdlib.h>

void print_error(char *message);
void print_menu();
float calculate_result(int op, float num1, float num2);

int
main()
{
    int op, c;
    float num1, num2, result;

    while(1) {
        system("clear");
        print_menu();

        do {
            printf("Please enter the operation option: ");
            if (scanf("%d", &op) != 1) {
                print_error("Invalid operation option selected");
            } else if (op < 1 || op > 5) {
                print_error("Invalid operation option selected");
            } else {
                break;
            }
        } while (1);
        
        if (op == 5) {
            printf("Exiting calculator program.\n");
            break;
        }

        do {
            printf("Please enter the first number: ");
            if (scanf("%f", &num1) != 1) {
                print_error("Invalid value input for first number");
                continue;
            } else {
                break;
            }
        } while (1);

        do {
            printf("Please enter the second number: ");
            if (scanf("%f", &num2) != 1) {
                print_error("Invalid value input for second number");
                continue;
            }
            
            if (num2 == 0 && op == 4) {
                print_error("Cannot divide by zero");
            } else {
                break;
            }
        } while (1);

        result = calculate_result(op, num1, num2);  
        printf("Result: %.2f\n", result);
        while ((c = getchar()) != '\n' && c != EOF);
        printf("\nPress anything to continue: ");
        getchar();
    }
    return 0;
}

void
print_error(char *message)
{
    int c;
    fprintf(stderr, "Error: %s\n", message);
    printf("\n");
    while ((c = getchar()) != '\n' && c != EOF);
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

float
calculate_result(int op, float num1, float num2)
{
    float result;
    switch (op)
    {
    case 1:
        result = num1 + num2;
        break;
    case 2:
        result = num1 - num2;
        break;
    case 3:
        result = num1 * num2;
        break;
    case 4:
        result = num1 / num2;
        break;
    default:
        result = 0;
        break;
    }
    return result;
}