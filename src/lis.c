#include "../include/push_swap.h"

// 'lis' - longest increasing subsequence
Int_array *lis(Stack *stack) {
	int i;
	int j;
	int *d;// d[i] is the length of the 'lis' that ends at the s_arr[i] 
	int *p;// p[i] is the index j of the second last element in 'lis' ending in 'i'. 
	int *s_arr; //stack_array: array for keeping the stack
	int s_len; //stack length
	int max_lis_ix; //index of maximum value in 'd'
	Int_array *lis_restored; //array to keep restored 'lis'
	Node *i_node;
	
	s_len = stack->length;
	s_arr = (int*)ft_calloc(s_len, sizeof(int));
	d = (int*)ft_calloc(s_len, sizeof(int)); 
	p = (int*)ft_calloc(s_len, sizeof(int));
	if(!d || !p || !s_arr) {
		fprintf(stderr, "Error - lis(): Allocation of memory has failed\n");
		exit(1);
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
	while(i < s_len) {
		d[i] = 1;
		p[i] = -1;
		i++;
	}

	 // calculate 'lis' for each i (0-n) and save in 'p' array under corresponding inex 'i'
	i = 0;
	i_node = stack->top;
	while(i < s_len) {
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
	//i = 0;
	//while(i < s_len) {
		//printf("d[%d]: %d\n", i, d[i]);
		//i++;
	//}

	//find max_lis_ix 
    j = d[0];
	max_lis_ix = 0;
	i = 0;
	while(i < s_len) {
		if(d[i] > j) {
			j = d[i];
			max_lis_ix = i;
		}
		i++;
	}

	////print 'p'
	//i = 0;
	//while(i < s_len) {
		//printf("p[%d]: %d\n", i, p[i]);
		//i++;
	//}

	lis_restored = (Int_array *)malloc(sizeof(Int_array));
	lis_restored->array = (int *)ft_calloc(d[max_lis_ix], sizeof(int));
	lis_restored->length = d[max_lis_ix];
	printf("MAX LEN = %d\n", d[max_lis_ix]);
	i = d[max_lis_ix] - 1;
	int pos = max_lis_ix;
	lis_restored->array[i] = s_arr[pos];
	while(p[pos] != -1) {
		lis_restored->array[--i] = s_arr[p[pos]];
		pos = p[pos];
	}

	i = 0;
	while(i < d[max_lis_ix]) {
		printf("r[%d]: %d\n", i, lis_restored->array[i]);
		i++;
	}

	free(s_arr);
	free(d);
	free(p);

    return lis_restored;
}