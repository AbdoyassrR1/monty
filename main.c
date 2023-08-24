#include "monty.h"

mon_t mon = {NULL, NULL, NULL};

/**
* main - Entry point of the Monty interpreter
* @argc: Number of args
* @argv: Array of args
* Return: 0 on success, or EXIT_FAILURE on failure
*/

int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	FILE *f;
	char *line = NULL;
	size_t size = 0;
	ssize_t r;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	f = fopen(argv[1], "r");
	mon.file = f;

	if (f == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((r = getline(&line, &size, f)) != -1)
	{
		line_number++;
		if (_execute(line, line_number, &stack) == 0)
			continue;
	}

	_free_stack(&stack);
	free(line);
	fclose(f);
	exit(EXIT_SUCCESS);

	return (0);
}
