#include <stdio.h>

void convert_f_to_c(double f);
void convert_c_to_f(double c);

int
main()
{
    double original;
    char unit;

    printf("(´• ω •`) ♡ TEMPERATURE CONVERTER (´ε｀ )♡\n");

    printf("Please enter the temperature you would like converted: ");
    scanf("%lf", &original);
    while ((getchar()) != '\n');
    printf("Please enter what unit to convert to (f/c): ");
    unit = getchar();

    if (unit == 'f') {
        convert_c_to_f(original);
    } else if (unit == 'c') {
        convert_f_to_c(original);
    } else {
        fprintf(stderr, "Please enter a valid unit to convert to: ");
    }
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