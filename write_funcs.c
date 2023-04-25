#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes the character c to print
 * @c: The character to print
 * Return: 1 On success -1 on error
 */
int _putchar(char c)
{
	static char buf[1024];
	static int i;

	if (c == -1 || i >= 1024)
	{
		write(1, &buf, i);
		i = 0;
	}
	if (c != -1)
	{
		buf[i] = c;
		i++;
	}
	return (1);
}

/**
 * _puts - prints a string to output
 * @str: pointer to the string to print
 * Return: number of chars passed to the func
 */
int _puts(char *str)
{
	register int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	return (i);
}
