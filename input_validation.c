
#include <stdio.h>
#include <stdbool.h>
#include <stack.h>

bool input_validation(int argc, char **argv, Stack *stack_a) {
    if(!enough_arguments(argc))
        return false;

	while(argc != 1) {
		
	}

}

bool enough_arguments(int argc) {
   	if (argc < 2) {
		fprintf(stderr, "Error: Insufficient arguments.\n");
		return false;
	} else
        return true;    
}