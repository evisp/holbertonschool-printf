#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

/**
 * handle_char - Handles printing a single character
 * @args: List of arguments
 * Return: Number of characters printed (always 1)
 */
int handle_char(va_list args)
{
    char c;

    c = va_arg(args, int);
    _putchar(c);

    return (1);
}

/**
 * handle_string - Handles printing a string
 * @args: List of arguments
 * Return: Number of characters printed
 */
int handle_string(va_list args)
{
    unsigned int i;
    char *s;

    s = va_arg(args, char *);

    if (s == NULL)
        s = "(null)"; /* Handle NULL strings gracefully */

    for (i = 0; s[i] != '\0'; i++)
    {
        _putchar(s[i]);
    }

    return (i);
}
