#include "monty.h"

/**
 * add - function that returns the sum of all the data (n) of a LL
 * @stack: pointer to head
 * Return: sum of all the data (n)
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (stack == NULL || ((*stack)->next) == NULL)
	{
		dprintf(2, "L%i: can't add, stack too short\n", line_number);
		exit_check = 1;
		return;
	}
	temp = (*stack)->next;
	temp->n += (*stack)->n;
	pop(stack, line_number);
}
