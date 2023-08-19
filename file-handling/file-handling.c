#include <stdio.h>
#include <string.h>

#define MAX_NUMBERS 100

void print_menu();
double calculate_sum(int *numbers, int count);
double find_maximum(int *numbers, int count);
double find_minimum(int *numbers, int count);

int
main()
{
    FILE *file;
    char fileName[256];
    int numbers[MAX_NUMBERS], operation, count = 0;
    double result = 0;

    printf("(´• ω •`) ♡ FILE HANDLING PROGRAM (´ε｀ )♡\n");
    printf("Please enter the name of the file: ");
    fgets(fileName, sizeof(fileName), stdin);
    sscanf(fileName, "%255[^\n]", fileName);

    file = fopen(fileName, "r");
    if (file == NULL) {
        printf("File %s not found. Please enter a valid file name. ", fileName);
        return 1;
    }

    while (count < MAX_NUMBERS && fscanf(file, "%d", &numbers[count]) == 1) {
        count++;
    }
    fclose(file);

    print_menu();
    printf("Please enter a valid operation (1 - 5): ");
    if (scanf("%d", &operation) != 1 || operation < 1 || operation > 5) {
        printf("Invalid input. Please enter a valid operation.");
        return 1;
    }
    
    switch(operation)
    {
        case 1:
            result = calculate_sum(numbers, count);
            break;
        case 2:
            result = calculate_sum(numbers, count) / count;
            break;
        case 3:
            result = find_maximum(numbers, count);
            break;
        case 4:
            result = find_minimum(numbers, count);
        case 5:
            printf("\nThank you for using the File Handling Program. Goodbye!\n");
            return 0;
        default:
            printf("Invalid operation selected.\n");
            return 1;
    }

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
calculate_sum(int *numbers, int count)
{
    double sum;
    for (int i = 0; i < count; i++) {
        sum += numbers[i];
    }
    return sum;
}

double
find_maximum(int *numbers, int count)
{
    double maximum = numbers[0];
    for (int i = 1; i < count; i++) {
        if (numbers[i] > maximum) {
            maximum = numbers[i];
        }
    }
    return maximum;
}

double
find_minimum(int *numbers, int count)
{
    double minimum = numbers[0];
    for (int i = 1; i < count; i++) {
        if (numbers[i] < minimum) {
            minimum = numbers[i];
        }
    }
    return minimum;
}