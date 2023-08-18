#include <stdio.h>

void convert_f_to_c(double f);
void convert_c_to_f(double c);

int
main()
{
    double original;
    char unit, again;
    int valid;

    printf("(´• ω •`) ♡ TEMPERATURE CONVERTER (´ε｀ )♡\n");

    do {
        printf("Please enter the temperature you would like converted: ");
        scanf("%lf", &original);
        while ((getchar()) != '\n');

        valid = 0;
        do {
            printf("Please enter what unit to convert to (f/c): ");
            unit = getchar();

            if (unit == 'f') {
                convert_c_to_f(original);
                valid = 1;
            } else if (unit == 'c') {
                convert_f_to_c(original);
                valid = 1;
            } else {
                fprintf(stderr, "Please enter what unit to convert to (f/c): ");
            }
            while ((getchar()) != '\n');
        } while (!valid);

        printf("Convert another temperature (y/n)? ");
        again = getchar();
        while ((getchar() != '\n'));
    } while (again == 'y');
}

void
convert_f_to_c(double f)
{
    double c;
    c = ((f - 32) * 5) / 9;
    printf("%.2f°F is %.2f°C\n", f, c);
}

void
convert_c_to_f(double c)
{
    double f;
    f = ((c * 9) / 5) + 32;
    printf("%.2f°C is %.2f°F\n", c, f);
}