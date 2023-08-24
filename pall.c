#include "monty.h"

/**
* _pall - Prints all the values on the stack, from top to bottom.
* @top: A ptr to the top of the stack.
* @line: The current line number in the Monty bytecode file.
* Return: void
*/

void _pall(stack_t **top, unsigned int line)
{
	stack_t *head = NULL;
	(void)line;

	head = *top;
	if (head == NULL)
		return;
	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}
