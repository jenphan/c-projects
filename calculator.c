#include <stdio.h>
#include <stdlib.h>

void clear_input_buffer();
void print_error(const char *message);
void print_menu();
int get_valid_operation();
float get_valid_float(const char *prompt);
float calculate_result(int op, float num1, float num2);

int
main()
{
    int op;
    float num1, num2, result;

    while(1) {
        system("clear");
        print_menu();

        op = get_valid_operation();
        
        if (op == 5) {
            printf("Exiting calculator program.\n");
            break;
        }

        num1 = get_valid_float("Please enter the first number: ");

        if (op == 4) {
            do {
                num2 = get_valid_float("Please enter the second number: ");
                if (num2 == 0 && op == 4) {
                    print_error("Cannot divide by zero");
                } else {
                    break;
                }
            } while (1);
        } else {
            num2 = get_valid_float("Please enter the second number: ");
        }

        result = calculate_result(op, num1, num2);  
        printf("Result: %.2f\n", result);
        clear_input_buffer();
        printf("\nPress anything to continue: ");
        getchar();
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
    printf("\n");
    clear_input_buffer();
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
get_valid_operation()
{
    int op;
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
    clear_input_buffer;
    return op;
}

float
get_valid_float(const char *prompt)
{
    float num;
    do {
        printf("%s", prompt);
        if (scanf("%f", &num) != 1) {
            print_error("Invalid value input for the number");
        } else {
            break;
        }
    } while (1);
    clear_input_buffer;
    return num;
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