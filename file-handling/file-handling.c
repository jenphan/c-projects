#include <stdio.h>
#include <string.h>

void print_menu();
void print_contents(char fileName[100]);

int
main()
{
    FILE *fp;
    char fileName[100];
    int c;

    printf("(´• ω •`) ♡ FILE HANDLING PROGRAM (´ε｀ )♡\n");
    printf("Please enter the name of the file: ");
    fgets(fileName, sizeof(fileName), stdin);
    fileName[strcspn(fileName, "\n")] = '\0';

    fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("File %s not found. Please enter a valid file name.", fileName);
        return 1;
    } 

    print_menu();

    fclose(fp);
    return 0;
}

void
print_menu()
{
    fprintf(stdout,
        "\n1. Calculate Sum\n"
        "2. Calculuate Average\n"
        "3. Find Maximum\n"
        "4. Find Minimum\n"
        "5. Exit\n\n");
}

void
print_contents(char fileName[100])
{
    FILE *fp;
    int c;
    printf("\nContents of %s:\n", fileName);
    while ((c = fgetc(fp)) != EOF) {
        putchar(c);
    }
}