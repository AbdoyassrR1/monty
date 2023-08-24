#include "monty.h"

/**
* pop - Removes the top element of the stack.
* @top: A ptr to the top of the stack.
* @line: The line number of the instruction being executed.
*/

void _pop(stack_t **top, unsigned int line)
{
	stack_t *temp;

	if (*top == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		free(mon.line);
		fclose(mon.file);
		_free_stack(top);
		exit(EXIT_FAILURE);
	}
	temp = *top;
	*top = temp->next;

	if (*top != NULL)
	{
		(*top)->prev = NULL;
	}

	free(temp);
}
