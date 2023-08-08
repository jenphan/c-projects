#include <stdio.h>
#include <stdlib.h>

#define ADD 1
#define SUBTRACT 2
#define MULTIPLY 3
#define DIVIDE 4
#define EXIT 5

void print_error(const char *message);
void print_menu();
int get_valid_int(const char *prompt, int min, int max);
float get_valid_float(const char *prompt);
float calculate_result(int op, float num1, float num2);

int
main()
{
    int op, c;
    float num1, num2, result;

    while(1) {
        system("clear");
        print_menu();

        op = get_valid_int("Please enter the operation option: ", 1, 5);
        
        if (op == EXIT) {
            printf("Exiting calculator program.\n");
            break;
        }

        num1 = get_valid_float("Please enter the first number: ");
        num2 = get_valid_float("Please enter the second number: ");

        result = calculate_result(op, num1, num2);  
        printf("Result: %.2f\n", result);
        printf("\nPress anything to continue: ");
        getchar();
    }
    return 0;
}

void
print_error(const char *message)
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

int
get_valid_int(const char *prompt, int min, int max)
{
    int value, c;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &value) != 1 || value < min || value > max) {
            print_error("Invalid operation option selected");
        } else {
            while ((c = getchar()) != '\n' && c != EOF);
            return value;
        }
    }
}

float
get_valid_float(const char *prompt)
{
    float value, c;
    while (1) {
        printf("%s", prompt);
        if (scanf("%f", &value) != 1) {
            print_error("Invalid value input for number");
        } else {
            while ((c = getchar()) != '\n' && c != EOF);
            return value;
        }
    }
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