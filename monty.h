#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>



/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
		int n;
		struct stack_s *prev;
		struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
		char *opcode;
		void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;



/**
* struct col_s - Struct for context data.
* @arg:  args string passed to Monty program.
* @line: Current line being processed from Monty file.
* @file: File ptr to Monty file being interpreted.
*/

typedef struct mon_s
{
	char *line;
	FILE *file;
	char *arg;
} mon_t;

extern mon_t mon;



int is_int(int n);
void _push(stack_t **top, unsigned int line);
void _pall(stack_t **top, unsigned int line);
void _free_stack(stack_t **stack);
void _push_stack(stack_t **top, int val);
int _execute(char *line, unsigned int line_num, stack_t **stack);
void _pop(stack_t **top, unsigned int line);
void _pint(stack_t **top, unsigned int line);
void _swap(stack_t **top, unsigned int line);
void _nop(stack_t **top, unsigned int line);
void _add(stack_t **top, unsigned int line);
void _sub(stack_t **top, unsigned int line);
void _mul(stack_t **top, unsigned int line);
void _stack_div(stack_t **top, unsigned int line);
void _stack_mod(stack_t **top, unsigned int line);
void _pstr(stack_t **top, unsigned int line);
void _rotr(stack_t **top, __attribute__((unused)) unsigned int line);
void _rotl(stack_t **top,  __attribute__((unused)) unsigned int line);
void _pchar(stack_t **top, unsigned int line);

#endif
