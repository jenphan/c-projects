#include <stdio.h>
#include <stdlib.h>
#include "calculator-functions.h"

int
main()
{
    while(1) {
        Operation op;
        float num1, num2, result;

        print_menu();

        op = get_valid_operation();
        
        if (op == EXIT) {
            fprintf(stdout, "Thank you for using the calculator program. Goodbye!\n");
            break;
        }

        num1 = get_valid_float("Please enter the first number: ");

        if (op == DIVIDE) {
            do {
                num2 = get_valid_float("Please enter the second number: ");
                if (num2 == 0) {
                    print_error("Cannot divide by zero");
                } else {
                    break;
                }
            } while (1);
        } else {
            num2 = get_valid_float("Please enter the second number: ");
        }

        result = calculate_result(op, num1, num2);  
        fprintf(stdout, "Result: %.2f\n\n", result);
    }
    return 0;
}

void
clear_input_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void
print_error(const char *message)
{
    fprintf(stderr, "Error: %s\n", message);
    fprintf(stdout, "\n");
}

void
print_menu()
{
    fprintf(stdout,
            "(´• ω •`) ♡ SIMPLE CALCULATOR MENU (´ε｀ )♡\n"
            "1. Addition\n"
            "2. Subtraction\n"
            "3. Multiplication\n"
            "4. Division\n"
            "5. Exit\n");
}

Operation
get_valid_operation()
{
    int op;
    char input[10];
    do {
        fprintf(stdout, "Please enter the operation option: ");
        fgets(input, sizeof(input), stdin);
        if (sscanf(input, "%d", &op) != 1 || op < 1 || op > 5) {
            print_error("Invalid operation option selected");
        } else {
            break;
        }
    } while (1);
    return op;
}

float
get_valid_float(const char *prompt)
{
    float num;
    char input[100];
    do {
        fprintf(stdout, "%s", prompt);
        fgets(input, sizeof(input), stdin);
        if (sscanf(input, "%f", &num) != 1) {
            print_error("Invalid value input for the number");
        } else {
            break;
        }
    } while (1);
    return num;
}

float
calculate_result(int op, float num1, float num2)
{
    float result;
    switch (op)
    {
    case ADD:
        result = num1 + num2;
        break;
    case SUBTRACT:
        result = num1 - num2;
        break;
    case MULTIPLY:
        result = num1 * num2;
        break;
    case DIVIDE:
        result = num1 / num2;
        break;
    default:
        result = 0;
        break;
    }
    return result;
}