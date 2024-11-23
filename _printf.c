#include "main.h"
#include <stdarg.h>
#include <stddef.h>

/**
 * _printf - Produces output according to a format
 * @format: Format string containing specifiers and text
 * 
 * Return: Number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    unsigned int i = 0, j = 0, flag = 0;
    unsigned int len = 0;

    specifier_t specifiers[] = {
        {"c", handle_char}, 
        {"s", handle_string}, 
        {NULL, NULL}
    };

    if (format == NULL || (format[0] == '%' && format[1] == '\0'))
        return (-1);

    va_start(args, format);

    while (format[i] != '\0')
    {
        if (format[i] == '%' && format[i + 1] != '%')
        {
            flag = 0;
            j = 0;
            while (specifiers[j].specifier != NULL)
            {
                if (format[i + 1] == specifiers[j].specifier[0])
                {
                    len += specifiers[j].handler(args);
                    flag = 1;
                    i++;
                    break;
                }
                j++;
            }
            if (!flag)
            {
                _putchar(format[i]);
                len++;
            }
        }
        else if (format[i] == '%' && format[i + 1] == '%')
        {
            _putchar('%');
            i++;
            len++;
        }
        else
        {
            _putchar(format[i]);
            len++;
        }
        i++;
    }

    va_end(args);
    return (len);
}
