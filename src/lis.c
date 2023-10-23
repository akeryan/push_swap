#include "../include/push_swap.h"

//longest increasing subsequence
int lis(Stack *stack) {
	int i;
	int j;
	int *d;
	int *p;
	int *s_arr; //stack_array: array for keeping the stack
	//int *lis_ix;
	int max_lis_len;
	Node *i_node;
	
	s_arr = (int*)ft_calloc(stack->length, sizeof(int));
	d = (int*)ft_calloc(stack->length, sizeof(int));
	p = (int*)ft_calloc(stack->length, sizeof(int));
	if(!d || !p || !s_arr) {
		fprintf(stderr, "Error - lis(): Allocation of memory has failed\n");
		exit(0);
	}

// copy stack to the s_arr array
	i = 0;
	i_node = stack->top;
	while(1) {
		s_arr[i++] = i_node->data;
		if(i_node->next == stack->top)
			break;
		i_node = i_node->next;
	}

// initialize 'd' and 'p' arrays
	i = 0;
	while(i < stack->length) {
		d[i] = 1;
		p[i] = -1;
		i++;
	}

 // calculate 'lis' for each i (0-n) and save in 'p' array under corresponding inex 'i'
	i = 0;
	i_node = stack->top;
	while(i < stack->length) {
		j = 0;
		while(j < i) {
			if(s_arr[j] < s_arr[i] && d[i] < d[j] + 1) {
				d[i] = d[j] + 1;
				p[i] = j;
			}
			j++;
		}
		i++;
	}
	
	// print values of array 'd'
	i = 0;
	while(i < stack->length) {
		printf("d[%d]: %d\n", i, d[i]);
		i++;
	}

	// find the maximum 'lis' length (max_lis_len) in 'd' array and corresponding index (max_lis_ix)
    max_lis_len = d[0];
	int max_lis_ix = 0;
	i = 0;
	while(i < stack->length) {
		if(d[i] > max_lis_len) {
			max_lis_len = d[i];
			max_lis_ix = i;
		}
		i++;
	}

	i = 0;
	while(i < stack->length) {
		printf("p[%d]: %d\n", i, p[i]);
		i++;
	}

	//lis_ix = (int *)ft_calloc(max_len, sizeof(int));
	//printf("max index = %d\n", max_index);
	//i = max_index - 1;
	//int pos = max_index;
	////lis_ix[i--] = d[max_index];
	//while(d[i] != 1) {
		//lis_ix[i] = a[pos];
	//}
    return max_lis_len;
}
