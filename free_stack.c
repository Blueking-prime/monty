#include "monty.h"

/**
* free_stack - frees a stack_t list
* @head: pointer to list to be freed
* Return: void
*/
void free_stack(stack_t *head)
{
	stack_t *current;

	while (head != NULL)
	{
		current = head;
		head = head->next;
		free(current);
	}
}

/**
* comp_1 - adds a new node at the end of a listint_t list
* @command: pointer to pointer of first node of listint_t list
* @head: integer to be included in new node
* @count: integer to be included in new node
* Return: address of the new element or NULL if it fails
*/

int comp_1(char *command, stack_t *head, unsigned int count)
{
	int i;
	char *pint_ = "pint";
	char *swap_ = "swap";
	char *add_ = "add";

	for (i = 0; pint_[i] != '\0'; i++)
	{
		if (command[i] != pint_[i])
			break;
	}
	if (i == 4)
	{
		pint(&head, count);
		return (0);
	}

	for (i = 0; swap_[i] != '\0'; i++)
	{
		if (command[i] != swap_[i])
			break;
	}
	if (i == 4)
	{
		swap(&head, count);
		return (0);
	}

	for (i = 0; add_[i] != '\0'; i++)
	{
		if (command[i] != add_[i])
			break;
	}
	if (i == 3)
	{
		add(&head, count);
		return (0);
	}

	return (-1);
}

/**
* comp_2 - adds a new node at the end of a listint_t list
* @command: pointer to pointer of first node of listint_t list
* @head: integer to be included in new node
* @count: integer to be included in new node
* Return: address of the new element or NULL if it fails
*/

int comp_2(char *command, stack_t *head, unsigned int count)
{
	int i;
	char *pop_ = "pop";
	char *nop_ = "nop";
	char *pall_ = "pall";

	for (i = 0; pop_[i] != '\0'; i++)
	{
		if (command[i] != pop_[i])
			break;
	}
	if (i == 3)
	{
		pop(&head, count);
		return (0);
	}

	for (i = 0; pall_[i] != '\0'; i++)
	{
		if (command[i] != pall_[i])
			break;
	}
	if (i == 4)
	{
		pall(&head);
		return (0);
	}

	for (i = 0; nop_[i] != '\0'; i++)
	{
		if (command[i] != nop_[i])
			break;
	}
	if (i == 3)
	{
		nop(&head, count);
		return (0);
	}

	return (-1);
}
