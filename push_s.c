#include "monty.h"

/**
* _push_stack - Pushes a new element onto the stack.
*
* @top: A pointer to the top of the stack.
* @val: The value to be pushed onto the stack.
*/

void _push_stack(stack_t **top, int val)
{
	stack_t *new_n;

	new_n = malloc(sizeof(stack_t));
	if (new_n == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_n->n = val;
	new_n->prev = NULL;
	new_n->next = NULL;

	if (*top != NULL)
	{
		new_n->next = *top;
		(*top)->prev = new_n;
	}

	*top = new_n;
}
