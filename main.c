#include "monty.h"

/**
 * main - monty program
 * @argc: total number of argument
 * @argv: array of arguments
 * Return: 0 , success
 */

int main(int argc, char **argv)
{
	
	FILE *fp = NULL;
	char *buffer = NULL, *instruction = NULL;
	size_t bufsize = 0, line_number = 1;
	void (*command)();
	stack_t *stack = NULL;
	instruction_t gf;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &bufsize, fp) != -1)
	{
		instruction = strtok(buffer, " \t\n");
		if (instruction == NULL)
		return (NULL);
		command = get_op_func(instruction);
			if (command != NULL)
				(*command)(&stack, line_number);
			else
			{
				dprintf(2, "L%i: unknown instruction %s\n", line_number, instruction);
				exit(EXIT_FAILURE);
			}
	}
	return (0);
}
