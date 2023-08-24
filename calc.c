#include "monty.h"

/**
* _add - Add the top two elements of the stack.
* @top: Double ptr to the top of the stack.
* @line: Line number of the current operation.
*/

void _add(stack_t **top, unsigned int line)
{
	int res;
	stack_t *temp;

	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		free(mon.line);
		fclose(mon.file);
		_free_stack(top);
		exit(EXIT_FAILURE);
	}

	res = (*top)->n + (*top)->next->n;
	temp = *top;
	*top = (*top)->next;
	(*top)->prev = NULL;
	(*top)->n = res;
	free(temp);

}


/**
* _sub - Subtract the top element of the stack from the second top element.
* @top: Double ptr to the top of the stack.
* @line: Line number of the current operation.
*/

void _sub(stack_t **top, unsigned int line)
{
	stack_t *temp;
	int res;

	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line);
		fclose(mon.file);
		free(mon.line);
		exit(EXIT_FAILURE);
	}

	res = (*top)->n - (*top)->next->n;
	temp = *top;
	*top = (*top)->next;
	(*top)->prev = NULL;
	(*top)->n = -(res);
	free(temp);

}

/**
* _mul - Multiplies the second top element of the stack with the top element
* @top: Double pointer to the top of the stack
* @line: Line number being executed from the Monty file
*/

void _mul(stack_t **top, unsigned int line)
{
	stack_t *tmp;
	int res;

	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line);
		fclose(mon.file);
		free(mon.line);
		exit(EXIT_FAILURE);
	}
		if (!is_int((*top)->n) || !is_int((*top)->next->n))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line);
		fclose(mon.file);
		free(mon.line);
		exit(EXIT_FAILURE);
	}
	res = (*top)->n * (*top)->next->n;
	tmp = *top;
	*top = (*top)->next;
	(*top)->prev = NULL;
	(*top)->n = res;
	free(tmp);

}
