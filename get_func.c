#include "monty.h"

/**
* get_op_func - Entry point
*
* @s: operation to use
*
* Return: (Always/Success)
*/

void (*get_op_func(char *s))(stack_t **, unsigned int)
{
	int i = 0;

	instruction_t ops[] = {
	{"pint", pint},
	{"pop", pop},
	{"swap", swap},
	{"add", add},
	{"nop", NULL},
	{NULL, NULL}
	};

	while (i < 7)
	{
		if (strcmp(s, ops[i].opcode) == 0)
			return (ops[i].f);
		i++;
	}
	return (ops[i].f);
}
