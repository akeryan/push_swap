#include "../include/push_swap.h"

//longest increasing subsequence
int lis(Stack *stack) {
	int i;
	int j;
	int *d;
	int *p;
	//int *lis_ix;
	int max_len;
	Node *i_node;
	Node *j_node;
	
	d = (int*)ft_calloc(stack->length, sizeof(int));
	p = (int*)ft_calloc(stack->length, sizeof(int));
	if(!d || !p) {
		fprintf(stderr, "Error - lis(): Allocation of memory has failed\n");
		exit(0);
	}

	i = 0;
	while(i < stack->length) {
		d[i] = 1;
		p[i] = -1;
		i++;
	}

	i = 0;
	i_node = stack->top;
	while(i < stack->length) {
		j = 0;
		j_node = stack->top;
		while(j < i) {
			if(j_node->data < i_node->data && d[i] < d[j] + 1) {
				d[i] = d[j] + 1;
				p[i] = j;
			}
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
	int max_index = 0;
	i = 0;
	while(i < stack->length) {
		if(d[i] > max_len) {
			max_len = d[i];
			max_index = i;
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
    return max_len;
}
