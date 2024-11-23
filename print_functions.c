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

/**
 * handle_int - Retrieves and prints an integer
 * @args: List of arguments passed to _printf
 *
 * Return: Number of characters printed
 */
int handle_int(va_list args)
{
    int value = va_arg(args, int);
    return print_number(value);
}

/**
 * print_number - Recursively prints an integer
 * @n: The number to print
 *
 * Return: Total number of characters printed
 */
int print_number(long int n)
{
    int count = 0;

    if (n < 0)
    {
        _putchar('-');
        count++;
        n = -n;
    }
    if (n / 10)
    {
        count += print_number(n / 10);
    }
    _putchar((n % 10) + '0');
    count++;

    return count;
}
