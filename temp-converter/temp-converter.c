#include <stdio.h>
#include <ctype.h>

void convert_f_to_c(double f);
void convert_c_to_f(double c);

int
main()
{
    double original;
    char unit, again;

    printf("(´• ω •`) ♡ TEMPERATURE CONVERTER (´ε｀ )♡\n");

    do {
        printf("Please enter the temperature you would like converted: ");
        while (scanf("%lf", &original) != 1 || getchar() != '\n') {
            printf("Invalid input. Please enter a valid temperature: ");
            while ((getchar()) != '\n');
        }

        do {
            printf("Please enter what unit to convert to (f/c): ");
            unit = tolower(getchar());

            if (unit == 'f') {
                convert_c_to_f(original);
            } else if (unit == 'c') {
                convert_f_to_c(original);
            }
            while ((getchar()) != '\n');
        } while (unit != 'f' && unit != 'c');

        printf("\nConvert another temperature (y/n)? ");
        while ((again = getchar()) == '\n');
    } while (again == 'y' || again == 'Y');

    printf("\nThank you for using the temperature converter! Goodbye!\n");
    return 0;
}

void
convert_f_to_c(double f)
{
    double c = (f - 32) * 5 / 9;
    printf("%.2f°F is %.2f°C\n", f, c);
}

void
convert_c_to_f(double c)
{
    double f = ((c * 9) / 5) + 32;
    printf("%.2f°C is %.2f°F\n", c, f);
}