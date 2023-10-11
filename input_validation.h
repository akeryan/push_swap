#ifndef INPUT_VALIDATION_H
#define INPUT_VALIDATION_H

#include "stack.h"

bool input_validation(int argc, char **argv, Stack *stack_a);
bool enough_arguments(int argc);
int check_and_push(char** str, Stack* stack);

#endif