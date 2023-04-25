#include "main.h"

/**
 * print_bigS - print Non printable characters
 * @l: va_list arguments from _printf
 * @f: pointer to determines if a flag is passed to _printf
 * Return: number of char printed
 */
int print_bigS(va_list l, flags_t *f)
{
	int i, sum = 0;
	char *res;
	char *s = va_arg(l, char *);

	(void)f;
	if (!s)
		return (_puts("(null)"));

	for (i = 0; s[i]; i++)
	{
		if (s[i] > 0 && (s[i] < 32 || s[i] >= 127))
		{
			_puts("\\x");
			sum += 2;
			res = convert(s[i], 16, 0);
			if (!res[1])
				sum += _putchar('0');
			sum += _puts(res);
		}
		else
			sum += _putchar(s[i]);
	}
	return (sum);
}

/**
 * print_rev - prints a string reversed
 * @l: argument from _printf
 * @f: pointer that determines if a flag is passed to _printf
 * Return: length of the printed string
 */
int print_rev(va_list l, flags_t *f)
{
	int i = 0, k;
	char *s = va_arg(l, char *);

	(void)f;
	if (!s)
		s = "(null)";

	while (s[i])
		i++;

	for (k = i - 1; k >= 0; k--)
		_putchar(s[k]);

	return (i);
}

/**
 * print_rot13 - prints a string using rot13
 * @l: list of arguments from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: length of the printed string
 */
int print_rot13(va_list l, flags_t *f)
{
	int i, k;
	char rot13[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char ROT13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *s = va_arg(l, char *);

	(void)f;
	for (k = 0; s[k]; k++)
	{
		if (s[k] < 'A' || (s[k] > 'Z' && s[k] < 'a') || s[k] > 'z')
			_putchar(s[k]);
		else
		{
			for (i = 0; i <= 52; i++)
			{
				if (s[k] == rot13[k])
					_putchar(ROT13[i]);
			}
		}
	}

	return (k);
}

/**
 * print_percent - prints a percent
 * @l: va_list arguments from _printf
 * @f: pointer to the struct flags in which we turn the flags on
 * Return: number of char printed
 */
int print_percent(va_list l, flags_t *f)
{
	(void)l;
	(void)f;
	return (_putchar('%'));
}
