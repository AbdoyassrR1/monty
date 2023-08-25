#include "monty.h"

/**
 * f_pchar - prints the char at the top of the stack,
 * followed by a new line
 * @top: stack head
 * @line: line_number
 * Return: no return
*/

void _pchar(stack_t **top, unsigned int line)
{
	stack_t *head;

	head = *top;
	if (!head)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line);
		fclose(mon.file);
		free(mon.line);
		_free_stack(top);
		exit(EXIT_FAILURE);
	}
	if (head->n > 127 || head->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line);
		fclose(mon.file);
		free(mon.line);
		_free_stack(top);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", head->n);
}
