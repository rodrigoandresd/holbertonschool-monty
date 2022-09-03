#include "monty.h"

/**
 * add - function that returns the sum of all the data (n) of a LL
 * @stack: pointer to head
 * Return: sum of all the data (n)
 */
void add(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		dprintf(2, "L%i: can't add, stack too short\n", line_number);
		exit_check = 1;
		return;
	}
	sum = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = sum;
	pop(stack, line_number);
}

/**
 * nop - function that "doesn’t do anything"
 * @stack: double pointer, pointer to a pointer to the head node
 * @line_number: index of the bytecode line where function is called
 * Return: void
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

