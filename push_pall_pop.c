#include "monty.h"

/**
* push - adds a new node at the end of a listint_t list
* @head: pointer to pointer of first node of listint_t list
* @n: integer to be included in new node
* Return: address of the new element or NULL if it fails
*/
stack_t *push(stack_t **head, int n)
{
	stack_t *new;
	stack_t *current;

	current = *head;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);

	new->prev = NULL;
	new->n = n;
	new->next = NULL;

	if (*head == NULL)
		*head = new;
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = new;
		new->prev = current;
	}

	return (new);
}

/**
* pall - prints all elements of a dlistint_t list
* @h: pointer to head of list
* Return: number of nodes
*/
size_t pall(stack_t **h)
{
	const stack_t *current;
	unsigned int n;

	current = *h;
	n = 0;
	while (current->next != NULL)
		current = current->next;

	while (current != NULL)
	{
		printf("%i\n", current->n);
		current = current->prev;
		n++;
	}

	return (n);
}

/**
* pop - deletes a node at a point in a stack_t list
* @head: pointer to pointer of first node of stack_t list
* Return: address of the new element or NULL if it fails
*/

void pop(stack_t **head, unsigned int line_no)
{
	stack_t *current;

	current = *head;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack", line_no);
		exit(EXIT_FAILURE);
	}

	while (current->next != NULL)
	{
		current = current->next;
	}

	if (current->prev == NULL)
	{
		*head = current->next;
		free(current);
	}
	else
	{
		current->prev->next = NULL;
		free(current);
	}
}
