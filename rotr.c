#include "monty.h"

/**
  *_rotr- rotates the stack to the bottom
  *@top: stack head
  *@line: line_number
  *Return: no return
 */

void _rotr(stack_t **top, __attribute__((unused)) unsigned int line)
{
	stack_t *cpy;

	cpy = *top;
	if (*top == NULL || (*top)->next == NULL)
	{
		return;
	}
	while (cpy->next)
	{
		cpy = cpy->next;
	}
	cpy->next = *top;
	cpy->prev->next = NULL;
	cpy->prev = NULL;
	(*top)->prev = cpy;
	(*top) = cpy;
}
