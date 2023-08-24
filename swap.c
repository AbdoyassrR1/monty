#include "monty.h"

/**
* _swap - swaps the top two elements of the stack
* @top: double pointer to the top of the stack
* @line: line number of the opcode
* Description: If the stack contains less than two elements, swap.
* Return: void
*/

void _swap(stack_t **top, unsigned int line)
{
	stack_t *temp = *top;
	int data;


	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		free(mon.line);
		fclose(mon.file);
		_free_stack(top);
		exit(EXIT_FAILURE);
	}
	temp = *top;
	data = temp->n;
	temp->n = temp->next->n;
	temp->next->n = data;

}
