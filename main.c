#include "monty.h"

/**
 * main - monty program
 * @argc: total number of argument
 * @argv: array of arguments
 * Return: 0 , success
 */

int main(int argc, char **argv)
{
	int gf = 0;
	FILE *fp = NULL;
	char *buffer = NULL, *token = NULL, *line[2], arg;
	size_t bufsize = 0, line_number = 1;
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
		token = strtok(buffer, " \t\n");
		if (token == NULL)
		return (NULL);
		line[0] = token;
		if (token != NULL)
		{
			arg = strtok(NULL, " \n\t");

			gf = get_op_func(line[0]);
			if (gf != NULL)
		}
		else
		{
			dprintf(2, "L%i: unknown instruction %s\n", line_number, line[0]);
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}
