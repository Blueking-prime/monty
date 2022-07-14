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

ssize_t readd_textfile(const char *filename, size_t letters)
{
	int fd, write_byte_no, close_return, read_return;
	ssize_t write_count;
	char *buffer;

	if (filename == NULL)
	{
		return (0);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		return (0);
	}
	buffer = malloc(letters * sizeof(char));
	if (buffer == NULL)
	{
		return (0);
	}
	read_return = read(fd, buffer, letters);
	if (read_return == -1)
	{
		return (0);
	}
	write_byte_no = write(STDOUT_FILENO, buffer, letters);
	if (write_byte_no == -1)
	{
		return (0);
	}
	write_count = write_byte_no / sizeof(char);
	free(buffer);
	close_return = close(fd);
	if (close_return == -1)
	{
		return (0);
	}
	return (write_count);
}
