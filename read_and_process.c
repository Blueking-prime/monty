#include "monty.h"

/**
* read_textfile - Entry point
*
* @filename: name of file to be read
*
* @head: name of file to be read
*
* Return: number of letters read and printed
*/

int read_textfile(const char *filename, stack_t *head)
{
	FILE *monty_file;
	char *buf = NULL;
	char **command_set = NULL;
	size_t bufsize = 0;
	unsigned int count = 1;

	monty_file = fopen(filename, "r");
	if (monty_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while (getline(&buf, &bufsize, monty_file) != -1)
	{
		command_set = split_buf(buf);

		if (strcmp(command_set[0], "push") == 0)
			push(&head, command_set[1], count);
		else
		{
			if (comp_1(command_set[0], head, count) == 0)
				;
			else if (comp_2(command_set[0], head, count) == 0)
				;
			else
			{
				count++;
				continue;
			}
		}
		count++;
	}
	fclose(monty_file);
	free(command_set);
	free_stack(head);
	return (EXIT_SUCCESS);
}

/**
 * split_buf - function that tokenizes a string with spaces, tabs and
 * new lines as delimiters
 * @buf: command line passed in by the user on standard input, string to be
 * parsed
 * Return: double pointer to an array (array of pointers to strings consisting
 * of the individual strings typed in by the user)
 */

char **split_buf(char *buf)
{
	int i = 0, count = 0;
	char *token = NULL;
	char **array_buf = NULL;

	count = token_count_buf(buf);
	if (count == 0)
		return (NULL);

	array_buf = malloc(sizeof(char *) * (count + 1));
	if (array_buf == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(array_buf);
		exit(EXIT_FAILURE);
	}
	token = strtok(buf, " \n\t");
	while (token != NULL)
	{
		array_buf[i] = token;
		i++;
		token = strtok(NULL, " \n\t");
	}
	i++;
	array_buf[i] = NULL;
	return (array_buf);
}

/**
 * token_count_buf - function that counts the number of strings typed in by
 * the user (in buf)
 * @buf: command line passed in by the user on standard input, string to be
 * parsed
 * Return: token/string count
 */

int token_count_buf(char *buf)
{
	int count = 0;

	while (*buf != '\0')
	{
		if (*buf == ' ' || *buf == '\t')
			count++;
		buf++;
	}
	count++;
	return (count);
}
