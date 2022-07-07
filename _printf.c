#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: character string
 * Return: number of characters printed excluding null byte
 */
int _printf(const char *format, ...)
{
  /*
  va_list arguments;
  const char *p;
  int num = 0;

  if (format == NULL)
    return (-1);
  
  va_start(arguments, format);

  for (p = format; *p; p++)
    {
      if (*p == '%' && *p + 1 == '%')
	{
	  _putchar(*p), num++;
	  continue;
	}
      else if (*p == '%' && *p + 1 != '%')
	{
	  switch (*++p)
	    {
	    case 's':
	      num += p_str(arguments);
	      break;
	    case 'c':
	      num += p_char(arguments);
	      break;
	    case '%':
	      _putchar('%'), num++;
	      break;
	    case '\0':
	      return (-1);
	    case 'i':
	    case 'd':
	      num += p_int(arguments);
	      break;
	    default:
	      _putchar('%'), _putchar(*p), num += 2;
	    }
	}
      else
	_putchar(*p), num++;
    }
  va_end(arguments);
  return (num);
  
  */
  va_list arg;
  unsigned int i, j, flag;
  unsigned int len = 0;

  print_t print[] = {
		     {"c", p_char}, {"s", p_str}, {"d", p_dec}, {"i", p_int},
		     {NULL, NULL}
  };

  va_start(arg, format);

  if (format == NULL || (format[0] == '%' && format[1] == '\0'))
    return (0);

  i = 0;
  while (format[i] != '\0')
    {
      if (format[i] == '%' && format[i + 1] != '%')
	{
	  j = 0;
	  flag = 0;
	  while (print[j].p != NULL)
	    {
	      if (format[i + 1] == print[j].print[0])
		{
		  len = len + print[j].p(arg);
		  flag = 1;
		  i++;
		}
	      j++;
	    }
	  if (flag == 0)
	    {
	      _putchar(format[i]);
	      len = len + 1;
	    }
	}
      else if (format[i] == '%' && format[i + 1] == '%')
	{
	  _putchar('%');
	  i++;
	  len = len + 1;
	}
      else
	{
	  _putchar(format[i]);
	  len = len + 1;
	}
      i++;
    }
  va_end(arg);

  return (len);
  
}
