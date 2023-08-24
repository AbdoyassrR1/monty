#include "monty.h"

/**
* free_stack - Frees all the nodes of a stack.
* @stack: ptr to the top of the stack.
*/

void _free_stack(stack_t **stack)
{
	stack_t *curr = *stack;
	stack_t *temp = NULL;

	while (curr != NULL)
	{
		temp = curr;
		curr = curr->next;
		free(temp);
	}

	*stack = NULL;
}
