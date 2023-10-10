#include <stdio.h>
#include "stack.h"
#include "libft.h"

int main(int argc, char *argv[]) {
	char **input;
	int i;

    	if (argc < 2) {
	       	fprintf(stderr, "Error: Insufficient arguments.\n");
        	return 1;
    	}

	Stack stack;
	initialize(&stack);


	return (0);
}



