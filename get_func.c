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
	{"nop", nop},
	{NULL, NULL}
	};

	while (i < 7)
	{
		if (strcmp(s, ops[i].opcode) == 0)
			return (ops[i].f);
		i++;
	}
	return (NULL);
}

/**
* nop - deletes a node at a point in a stack_t list
* @h: pointer to pointer of first node of stack_t list
* @line_no: integer to be included in new node
* Return: address of the new element or NULL if it fails
*/
void nop(stack_t **h, unsigned int line_no)
{
	const stack_t *current;
	unsigned int n;

	if (line_no == 0)
		current = *h;

	if (current == *h)
		n = line_no;

	n++;
}
