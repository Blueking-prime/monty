#include "monty.h"

/**
 * main - function that executes command line operations
 * @ac: argument count
 * @av: double pointer, pointer to string of pointers to the command line
 * arguments
 * Return: Always 0
 */

int main(int ac, char **av)
{
	stack_t *head = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	read_textfile(av[1], head);

	return (EXIT_SUCCESS);
}
