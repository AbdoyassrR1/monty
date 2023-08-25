#include "monty.h"

/**
  *f_rotl- rotates the stack to the top.
  *@line: stack head.
  *@top: line_number.
  *Return: no return
 */

void _rotl(stack_t **top,  __attribute__((unused)) unsigned int line)
{
	stack_t *temp = *top, *aux;

	if (*top == NULL || (*top)->next == NULL)
	{
		return;
	}
	aux = (*top)->next;
	aux->prev = NULL;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = *top;
	(*top)->next = NULL;
	(*top)->prev = temp;
	(*top) = aux;
}
