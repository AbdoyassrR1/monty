#include "monty.h"

/**
* nop - does nothing
* @top: double pointer to the top of the stack
* @line: line number of the opcode
* Description: This opcode does nothing.
* Return: void
*/

void _nop(stack_t **top, unsigned int line)
{
	(void)top;
	(void)line;
}
