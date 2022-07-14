#include "monty.h"

/**
* read_textfile - Entry point
*
* @filename: name of file to be read
*
* @letters: numberof letters to be read from the file
*
* Return: number of letters read and printed
*/

int read_textfile(const char *filename, stack_t *head)
{
	FILE *monty_file;
	char *buf = NULL;
	char **command_set;
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
		printf("%s ", command_set[0]);
		if (get_op_func(command_set[0]) == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s", count, command_set[0]);
			exit(EXIT_FAILURE);
		}
		if (strcmp(command_set[0], "push") == 0)
			push(&head, atoi(command_set[1]));
		else if (strcmp(command_set[0], "pall") == 0)
			pall(&head);
		else
			get_op_func(command_set[0])(&head, count);
		count++;
	}

	fclose(monty_file);
	return (EXIT_SUCCESS);
}

/**
 * split_buf - function that tokenizes a string with spaces, tabs and new lines
 * as delimiters
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
	printf("%d", count);
	if (count == 0)
		return (NULL);

	array_buf = malloc(sizeof(char *) * (count + 1));
	if (array_buf == NULL)
		exit(1);

	token = strtok(buf, " \n\t");
	while (token != NULL)
	{
		array_buf[i] = token;
		i++;
		token = strtok(NULL, " \n\t");
	}

	array_buf[i] = NULL;
	return (array_buf);
}

/**
 * token_count_buf - function that counts the number of strings typed in by the
 * user (in buf)
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
