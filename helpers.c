#include "monty.h"
/**
 * isnumber - function that checks strings of digits
 * and converts the string to an integer if all characters are digits
 * @str: string passed from main (string pointed to by array[1])
 * @line_number: index of the bytecode line where function is called
 * Return: n, integer to be stored as global variable, -1 if not integer
 */
int isnumber(char *str, unsigned int line_number)
{
	int i = 0, n = 0;

	if (!str)
	{
		dprintf(2, "L%i: usage: push integer\n", line_number);
		exit_check = 2;
		return (-1);
	}
	if (str[0] == '-')
		i = 1;
	for (; str[i] != '\0'; i++)
		if (!isdigit(str[i]))
		{
			dprintf(2, "L%i: usage: push integer\n", line_number);
			exit_check = 2;
			return (-1);
		}
	n = atoi(str);
	return (n);
}

/**
 * exit_fail_check - function that frees and close(fp) before exiting
 * @buffer: buffer created by getline for each line being read from file
 * @fp: pointer returned by fopen function
 * @stack: pointer to head node passed from main
 * Return: void
 */

void exit_fail_check(char *buffer, FILE *fp, stack_t *stack)
{
	if (exit_check == 1)
	{
		free(buffer);
		fclose(fp);
		free_stackt(stack);
		exit(EXIT_FAILURE);
	}
		if (exit_check == 2)
	{
		fclose(fp);
		free_stackt(stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * free_stackt - function that frees a stack_t list
 * @stack: pointer to free
 * Return: void
 */
void free_stackt(stack_t *stack)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

