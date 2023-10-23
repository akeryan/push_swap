#include "../include/push_swap.h"

//longest increasing subsequence
int lis(Stack *stack) {
	int i;
	int j;
	int *d;
	int max_len;
	Node *i_node;
	Node *j_node;
	
	d = (int*)calloc(stack->length, sizeof(int));
	if(!d) {
		fprintf(stderr, "Error - lis(): Allocation of memory has failed\n");
		exit(0);
	}

	i = 0;
	while(i < stack->length) {
		d[i] = 1;
		i++;
	}

	i = 0;
	i_node = stack->top;
	while(i < stack->length) {
		j = 0;
		j_node = stack->top;
		while(j < i) {
			if(j_node->data < i_node->data)
				d[i] = max(d[i], d[j] + 1);
			j++;
			j_node = j_node->next;
		}
		i++;
		i_node = i_node->next;
	}
	
	i = 0;
	while(i < stack->length) {
		printf("d[%d]: %d\n", i, d[i]);
		i++;
	}

    max_len = d[0];
	i = 0;
	while(i < stack->length) {
		max_len = max(max_len, d[i]);
		i++;
	}
    return max_len;
}
