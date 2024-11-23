#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

/**
 * struct specifier_t - Struct for format specifiers and their handlers
 * @specifier: The format specifier (e.g., "c", "s", "d")
 * @handler: Pointer to the function that handles the specifier
 */
typedef struct specifier_t
{
	char *specifier;
    int (*handler)(va_list args);
} specifier_t;

int _printf(const char *format, ...);
int _putchar(char c);

int handle_char(va_list args);
int handle_string(va_list args);
int handle_int(va_list args);

#endif
