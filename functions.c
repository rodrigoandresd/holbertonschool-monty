#include "monty.h"

/**
 * push - push function
 * @stack: head
 * @line_number: line_number
 * Return: Always 0 (Success)
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
}

/**
 * pall - pall function
 * @stack: head
 * @line_number: line_number
 * Return: void function
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	tmp = *stack;
	if (line_number)
		while (tmp)
		{
			printf("%d\n", tmp->n);
			tmp = tmp->next;
		}
}
