#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
/**
 * int_buffer - initialize the output
 * Return: a struct
 */

buffer_t *init_buffer(void)
{
        buffer_t *output;

        output = (buffer_t*)malloc(sizeof(buffer_t));
        if (output == NULL)
                return (NULL);

        output->buffer = (char*)malloc(sizeof(char) * 1024);
        if (output->buffer == NULL)
        {
                free(output);
                return (NULL);
        }

        output->start = output->buffer;
        output->len = 0;

        return (output);
}
/**
 * run_printf - run the printf
 * @format: a string of characters with format
 * @args: list arguments
 * @output: a struct containing the output
 * Return: the returnval
 */

int run_printf(const char *format, va_list args, buffer_t *output)
{
        int i, returnVal = 0;
        char tmp;
        unsigned char len;
        unsigned int (*f)(va_list, buffer_t *);
        
        for (i = 0; format[i]; i++)
        {
                len = 0;
                if (format[i] == '%')
                {
                        tmp = 0;
                        f = handle_specifiers(format + i + tmp + 1);
                        if (f != NULL)
                        {
                                i += tmp + 1;
                                returnVal += f(args, output);
                                continue;
                        }
                        else if (format[i + tmp + 1] == '\0')
                        {
                                returnVal = -1;
                                break;
                        }

                }
                returnVal += _memcpy(output, (format + i), 1);
                i += (len != 0) ? 1 : 0;
                
        }
        cleanup(args, output);
        return (returnVal);
}
/**
 * _printf - prints out it's argument
 * @format: string with different formats
 * Return: returnedval
 */

int _printf(const char *format, ...)
{
        buffer_t *output;
        va_list args;
        int returnValue;

        if (format == NULL)
                return (-1);
        output = init_buffer();
        if (output == NULL)
                return (-1);

        va_start(args, format);

        returnValue = run_printf(format, args, output);

        return (returnValue);
}
