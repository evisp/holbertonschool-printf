#include <stdio.h>
#include "main.h"

/**
 * main - Entry point to test _printf
 *
 * Return: Always 0
 */
int main(void)
{
    int len;

    len = _printf("Character: %c\n", 'A');
    len = _printf("String: %s\n", "Hello, World!");
    
	len = _printf("Percent sign: %%\n");
    len = _printf("Null string: %s\n", NULL);
    len = _printf("");
    len = _printf("Invalid specifier: %x\n");
	
	len = _printf("Integer: %d\n", 1024);  
    len = _printf("Integer: %d\n", -1024); 
    len = _printf("Integer: %i\n", 12345);  
    len = _printf("Integer: %i\n", -12345);  

    return (0);
}
