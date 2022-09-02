#include "monty.h"
/**
 * get_op_func - function that checks for opcodes and points to
 * the proper function pointer
 * @inst: string passed from main instruction
 * Return: NULL or pointer to the correct opcode function
 */

void (*get_op_func(char *inst))(stack_t **stack, unsigned int line_number)
{
	instruction_t opc[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};
	int i = 0, result = 0;

	while (i < 7)
	{
		result = strcmp(inst, opc[i].opcode);
		if (result == 0)
			return (opc[i].f);
		i++;
	}
	return (NULL);
}