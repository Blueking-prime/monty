#include "monty.h"

/**
* pint - adds a new node at a point in a stack_t list
* @h: pointer to pointer of first node of stack_t list
* @line_no: integer to be included in new node
* Return: address of the new element or NULL if it fails
*/

void pint(stack_t **h, unsigned int line_no)
{
	const stack_t *current;

	if (*h == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_no);
		exit(EXIT_FAILURE);
	}

	current = *h;
	while (current->next != NULL)
		current = current->next;

	printf("%i\n", current->n);
}

/**
* swap - adds a new node at a point in a stack_t list
* @h: pointer to pointer of first node of stack_t list
* @line_no: integer to be included in new node
* Return: address of the new element or NULL if it fails
*/

void swap(stack_t **h, unsigned int line_no)
{
	stack_t *current;
	int n, count = 0;

	current = *h;

	if (*h == NULL)
		exit(EXIT_FAILURE);

	while (current->next != NULL)
	{
		current = current->next;
		count++;
	}

	if (count < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_no);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}

	n = current->n;
	current->n = current->prev->n;
	current->prev->n = n;
}

/**
* add - adds a new node at a point in a stack_t list
* @h: pointer to pointer of first node of stack_t list
* @line_no: integer to be included in new node
* Return: address of the new element or NULL if it fails
*/

void add(stack_t **h, unsigned int line_no)
{
	stack_t *current;
	int n, count = 0;

	current = *h;

	if (*h == NULL)
		exit(EXIT_FAILURE);

	while (current->next != NULL)
	{
		current = current->next;
		count++;
	}

	if (count < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_no);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}

	n = current->n + current->prev->n;
	current->prev->n = n;

	pop(h, line_no);
}
