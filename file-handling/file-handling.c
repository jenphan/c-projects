#include <stdio.h>
#include <string.h>

void print_menu();
double perform_operation(int op, int *numbers, int count);

int
main()
{
    FILE *file;
    char fileName[100];
    double result;
    int numbers[100], operation, c;

    printf("(´• ω •`) ♡ FILE HANDLING PROGRAM (´ε｀ )♡\n");
    printf("Please enter the name of the file: ");
    fgets(fileName, sizeof(fileName), stdin);
    fileName[strcspn(fileName, "\n")] = '\0';

    file = fopen(fileName, "r");
    if (file == NULL) {
        printf("File %s not found. Please enter a valid file name.", fileName);
        return 1;
    }

    while (c < 100 && fscanf(file, "%d", &numbers[c]) == 1) {
        c++;
    }
    fclose(file);

    print_menu();
    printf("Please enter a valid operation (1 - 5): ");
    if (scanf("%d", &operation) != 1) {
        printf("Invalid input. Please enter a valid operation: ");
        return 1;
    }
    
    result = perform_operation(operation, numbers, c);
    printf("\nResult: %.2f\n", result);

    return 0;
}

void
print_menu()
{
    fprintf(stdout,
        "\n1. Calculate Sum\n"
        "2. Calculate Average\n"
        "3. Find Maximum\n"
        "4. Find Minimum\n"
        "5. Exit\n\n");
}

double
perform_operation(int op, int *num, int count)
{
    double result = 0;
    int i;
    switch (op)
    {
        case 1:
            for (i = 0; i < count; i++) {
                result += num[i];
            }
            break;
        case 2:
            for (i = 0; i < count; i++) {
                result += num[i];
            }
            result = result / count;
            break;
        case 3:
            result = num[0];
            for (i = 1; i < count; i++) {
                if (num[i] > result) {
                    result = num[i];
                }
            }
            break;
        case 4:
            result = num[0];
            for (i = 1; i < count; i++) {
                if (num[i] < result) {
                    result = num[i];
                }
            }
            break;
    }
    return result;
}