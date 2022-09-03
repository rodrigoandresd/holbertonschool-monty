#include "monty.h"

/**
 * add - function that returns the sum of all the data (n) of a LL
 * @stack: pointer to stack
 * @line_number: line_number
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
 * @stack: double pointer, pointer to a pointer to the stack node
 * @line_number: index of the bytecode line where function is called
 * Return: void
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * sub - function that subtracts the top element of the stack
 * from the second top element
 * @stack: double pointer, pointer to a pointer to the stack node
 * @line_number: index of the bytecode line where function is called
 * Return: void
 */

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (!(*stack) || !((*stack)->next))
	{
		dprintf(2, "L%i: can't sub, stack too short\n", line_number);
		exit_check = 1;
		return;
	}
	temp = (*stack)->next;
	temp->n -= (*stack)->n;
	pop(stack, line_number);
}

/**
 * mul - function that multiplies the second top element of the stack
 * with the top element of the stack
 * @stack: double pointer, pointer to a pointer to the stack node
 * @line_number: index of the bytecode line where function is called
 * Return: void
 */

void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (!(*stack) || !((*stack)->next))
	{
		dprintf(2, "L%i: can't mul, stack too short\n", line_number);
		exit_check = 1;
		return;
	}
	temp = (*stack)->next;
	temp->n *= (*stack)->n;
	pop(stack, line_number);
}

/**
 * mod - function that computes the rest of the division of
 * the second top element of the stack by the top element of the stack
 * @stack: double pointer, pointer to a pointer to the stack node
 * @line_number: index of the bytecode line where function is called
 * Return: void
 */

void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (!(*stack) || !((*stack)->next))
	{
		dprintf(2, "L%i: can't mod, stack too short\n", line_number);
		exit_check = 1;
		return;
	}
	if ((*stack)->n == 0)
	{
		dprintf(2, "L%i: division by zero\n", line_number);
		exit_check = 1;
		return;
	}
	temp = (*stack)->next;
	temp->n %= (*stack)->n;
	pop(stack, line_number);
}
