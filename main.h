#ifndef MAIN_H
#define MAIN_H

/**
 * struct buffer_s - struct of buffer containing the buffer string
 * @buffer: buffer string
 * @start: starting character
 * @len: length of buffer
 */

typedef struct buffer_s
{
	char *buffer;
	char *start;
	unsigned int len;
} buffer_t;

/**
 * struct converter_s - struct of converter
 * @specifier: specifier character of either 'c', 's', 'd' or 'i'
 * @func: specifier handler
 */

typedef struct converter_s
{
	unsigned char specifier;
	unsigned int (*func)(va_list, buffer_t *);
} converter_t;

int _printf(const char *format, ...);
buffer_t *init_buffer(void);
void cleanup(va_list args, buffer_t *output);
void free_buffer(buffer_t *output);

unsigned int _memcpy(buffer_t *output, const char *src, unsigned int n);
unsigned int convert_c(va_list args, buffer_t *output);
unsigned int convert_s(va_list args, buffer_t *output);
unsigned int (*handle_specifiers(const char *specifier))(va_list, buffer_t *);
int run_print(const char *format, va_list args, buffer_t *output);

#endif
