#include "monty.h"

/**
 * flush_buffer - cleanup
 * @buffer: a buffer
 * @size: size of buffer
 */
void flush_buffer(char *buffer, size_t size)
{
	size_t i;

	for (i = 0; i < size; ++i)
		buffer[i] = '\0';
}

/**
 * fill_buffer - fill buffer with '\0' char
 * @buf: pointer to buffer
 * @size: pointer to size of buffer
 * @c: char to insert at index
 * @index: index at which to enter char
 * since we need to insert '\0' at end of buffer, check we have room
 * or realloc
 */
void fill_buffer(char **buf, size_t *size, char c, size_t index)
{
	char *p;

	if (!buf || !size)
		return;
	if (index >= *size - 1)
	{
		*buf = realloc(*buf, *size * 2);
		if (*buf == NULL)
			return;
		*size = *size * 2;
	}
	p = *buf;
	*(p + index) = c;
}

/**
 * _getline - read a line from standard input
 * @buf: a pointer to a buffer
 * @size: size of buffer
 * @file_strm: input stream
 * Return: number of characters read on success, -1 otherwise
 */
ssize_t _getline(char **buf, size_t *size, int file_strm)
{
	size_t index;
	char c;
	int check_r;

	if (!buf || !size)
		return (-1);
	if (!*buf)
	{
		*size = BUF_LENGTH;
		*buf = malloc(*size * sizeof(char));
		if (*buf == NULL)
			return (-1);
	}
	index = 0;
	flush_buffer(*buf, *size);
	while (1)
	{
		check_r = read(file_strm, &c, 1);
		if (check_r == -1)
			return (-1);
		if (check_r == 0 && index == 0)
			return (-1);
		if (c != EOF)
		{
			fill_buffer(buf, size, c, index);
			if (*buf == NULL)
				return (-1);
			++index;
		}
		if (c == '\n')
			break;
	}
	*((*buf) + index - 1) = '\0';
	return (index);
}
