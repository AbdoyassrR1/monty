#include "monty.h"

/**
* _push - Adds a new element to the stack.
* @top: A ptr to the top of the stack.
* @line: The line number of the instruction being executed
*/

void _push(stack_t **top, unsigned int line)
{
	int val;
	char *end;

	if (mon.arg == NULL || *mon.arg == '\0' || isspace(*mon.arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line);
		_free_stack(top);
		free(mon.line);
		fclose(mon.file);
		exit(EXIT_FAILURE);
	}

	val = strtol(mon.arg, &end, 10);

	if (*end != '\0' || end == mon.arg ||
	 val > INT_MAX || val < INT_MIN)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line);
		_free_stack(top);
		free(mon.line);
		if (mon.file != NULL)
			fclose(mon.file);
		exit(EXIT_FAILURE);
	}

		_push_stack(top, val);
}
