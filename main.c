#include "monty.h"

/**
 * main - function that checks if the number of args is equal to 2
 * @argc: total number of argument count
 * @argv: argument vector
 * Return: 0 , success
 */

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_and_read(argv);
	return (0);
}
