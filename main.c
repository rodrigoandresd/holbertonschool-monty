#include "monty.h"

int exit_check = 0;

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
		{
			line_number++;
			free(buffer);
			continue;
		}
		command = get_op_func(instruction);
		if (strcmp("push", instruction) != 0)
		{
			dprintf(2, "L%i: unknown instruction %s\n", (int)line_number, instruction);
			exit_fail_push(buffer, fp, stack);
		}
		if (command != NULL)
			(*command)(&stack, line_number);
		else
			dprintf(2, "L%i: unknown instruction %s\n", (int)line_number, instruction);
		exit_fail_check(buffer, fp, stack);
		line_number++;
	}
	free(buffer), fclose(fp), free_stackt(stack);
	return (0);
}
