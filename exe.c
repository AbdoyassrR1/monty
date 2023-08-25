#include "monty.h"

/**
* _execute - Executes an opcode on a stack.
* @line: The line containing the opcode to execute.
* @line_num: The line number of the opcode in the input file.
* @stack: A pointer to the top of the stack.
* Return: 0 if the opcode is a comment or if the line is empty, 1 otherwise.
*/

int _execute(char *line, unsigned int line_num, stack_t **stack)
{
	instruction_t opcodes[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _stack_div}, {"rotl", _rotl},
		{"mod", _stack_mod}, {"rotr", _rotr},
		{"pstr", _pstr}, {"pchar", _pchar}, {NULL, NULL}
	};
	int index = 0;
	int found = 0;
	char *opcode;

	opcode = strtok(line, " \t\n");
	if (!opcode || *opcode == '#' || opcode[0] == '#')
	{
		return (0);
	}
	mon.arg = strtok(NULL, " \t\n");
	while (opcodes[index].opcode != NULL && opcode != NULL)
	{
		if (strcmp(opcode, opcodes[index].opcode) == 0)
		{
			opcodes[index].f(stack, line_num);
			found = 1;
			break;
		}
		index++;
	}
	if (found == 0)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_num, opcode);
		exit(EXIT_FAILURE);
	}
	return (1);
}
