#include "main.h"

/**
 * convert - converts to string
 * @num: input number
 * @base: input base
 * @lowercase: flag when hexa inputs need to be lowercase
 * Return: string converted
 */
char *convert(unsigned long int num, int base, int lowercase)
{
	static char *cvrt;
	static char buffer[50];
	char *ptr;

	cvrt = (lowercase)
		? "0123456789abcdef"
		: "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';
	do {
		*--ptr = cvrt[num % base];
		num /= base;
	} while (num != 0);

	return (ptr);
}
