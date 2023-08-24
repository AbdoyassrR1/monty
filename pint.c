#include "monty.h"

/**
* _pint - prints the value at the top of the stack, followed by a new line.
* @top: double pointer to the top of the stack.
* @line: line number of the opcode.
* Return: void
*/

void _pint(stack_t **top, unsigned int line)
{

	if (*top == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line);
		fclose(mon.file);
		free(mon.line);
		exit(EXIT_FAILURE);
	}

	else
	{
		printf("%d\n", (*top)->n);
	}

}
