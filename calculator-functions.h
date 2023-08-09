#ifndef CALCULATOR_FUNCTIONS_H
#define CALCULATOR_FUNCTIONS_H

typedef enum {
    ADD = 1,
    SUBTRACT,
    MULTIPLY,
    DIVIDE,
    EXIT
} Operation;

void clear_input_buffer();
void print_error(const char *message);
void print_menu();
Operation get_valid_operation();
float get_valid_float(const char *prompt);
float calculate_result(int op, float num1, float num2);

#endif