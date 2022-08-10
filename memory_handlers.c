#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * free_buffer - frees the  memory
 * @output: buffer to be freed
 */
void free_buffer(buffer_t *output)
{
	free(output->start);
	free(output);
}

/**
 * cleanup - end argument loop
 * @args: argument list
 * @output: output string
 */

void cleanup(va_list args, buffer_t output)
{
	va_end(args);
	free(output);
}

/**
 * _memcpy - copies src to the buffer string
 * @output: buffer string
 * @src: src of string
 * @n: number to be copied
 * Return: n
 */
unsigned int _memcpy(buffer_t *output, const char *src, unsigned int n)
{
	unsigned int index;

	for (index = 0; index < n; index++)
	{
		*(output->buffer) = *(src + index);
		(output->len)++;
		if (output->len == 1024)
		{
			write(1, output->start, output->len);
			output->buffer = output->start;
			output->len = 0;
		}
		else
			(outputt->buffer)++;
	}
	return (n);
}

