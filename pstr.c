#include "monty.h"

/**
 * _pstr - prints the string starting at the top of the stack,
 * followed by a new
 * @top: stack head
 * @line: line_number
 * Return: no return
*/

void _pstr(stack_t **top, unsigned int line)
{
	stack_t *h;
	(void)line;

	h = *top;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
