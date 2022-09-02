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
	
	token_num = strtok(NULL, " \t\r\n");

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

/**
 * pint - function that prints the value at the top of the stack
 * @stack: double pointer, pointer to a pointer to the head node
 * @line_number: index of the bytecode line where function is called
 * Return: void
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		dprintf(2, "L%i: can't pint, stack empty\n", line_number);
		exit_check = 1;
		return;
	}
	printf("%i\n", (*stack)->n);
}

/**
 * pop -  removes the top element of the stack
 * @stack: pointer to pointer head
 * @line_number: position of the node that should be deleted
 * Return: nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (*stack == NULL || stack == NULL)
	{
		dprintf(2, "L%i: can't pop an empty stack\n", line_number);
		exit_check = 1;
		return;
	}
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = NULL;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}
/**
 * swap - function that swaps the top two elements of the stack
 * @stack: double pointer, pointer to a pointer to the head node
 * @line_number: index of the bytecode line where function is called
 * Return: void
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (!(*stack) || !((*stack)->next))
	{
		dprintf(2, "L%i: can't swap, stack too short\n", line_number);
		exit_check = 1;
		return;
	}
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	(*stack)->prev = temp;
	temp->next = *stack;
	temp->prev = NULL;
	*stack = temp;
}