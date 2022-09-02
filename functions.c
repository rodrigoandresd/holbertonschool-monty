#include "monty.h"

/**
 * push - function adds a new node at the beginning of the stack
 * @stack: pointer to pointer head
 * @line_number: line_number
 * Return: Always 0 (Success)
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *newnode = NULL;
	int num;
	char *token_num = NULL;
	
	token_num = strtok(NULL, " \t\n");
	if (token_num == NULL)
	{
		exit_check = 2;
		return;
	}
	num = isnumber(token_num, line_number);

	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		exit_check = 1;
		return;
	}
	newnode->n = num;
	newnode->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = newnode;
	newnode->next = *stack;
	*stack = newnode;
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
