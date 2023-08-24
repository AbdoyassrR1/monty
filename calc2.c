#include "monty.h"

/**
* stack_div - Divide the second top element of the stack by the top element.
* @top: Double pointer to the top of the stack.
* @line: Line number of the current operation.
*/

void _stack_div(stack_t **top, unsigned int line)
{
	stack_t *temp;
	int res;

	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line);
		free(mon.line);
		fclose(mon.file);
		_free_stack(top);
		exit(EXIT_FAILURE);

	}

	if ((*top)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		free(mon.line);
		fclose(mon.file);
		_free_stack(top);
		exit(EXIT_FAILURE);

	}

	temp = *top;
	res = (*top)->next->n / (*top)->n;
	*top = (*top)->next;
	(*top)->n = res;
	if (*top != NULL)
	{
		(*top)->prev = NULL;
	}

	free(temp);
}



/**
* stack_mod- mod the second top element of the stack by the top element.
* @top: Double pointer to the top of the stack.
* @line: Line number of the current operation.
*/
void _stack_mod(stack_t **top, unsigned int line)
{
	stack_t *temp;
	int res;

	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line);
		free(mon.line);
		fclose(mon.file);
		_free_stack(top);
		exit(EXIT_FAILURE);

	}

	if ((*top)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		free(mon.line);
		fclose(mon.file);
		_free_stack(top);
		exit(EXIT_FAILURE);

	}
	temp = *top;
	res = (*top)->next->n % (*top)->n;
	*top = (*top)->next;
	(*top)->n = res;
	if (*top != NULL)
	{
		(*top)->prev = NULL;
	}
	free(temp);
}
