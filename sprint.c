#include "main.h"
/**
 * _sprint - printf in its simpliest form without using a format specifier
 * @str: string to print
 * Return: number of char
 */
int _sprint(const char *str)
{
	int i = 0, num_char;
	char *nstr;

	while (str[i])
		i++;
	nstr = malloc(sizeof(char) * (i + 1));
	if (nstr == NULL)
		exit(1);
	for (i = 0; str[i]; i++)
		nstr[i] = str[i];
	nstr[i] = '\0';
	num_char = write(1, nstr, i) - 1;
	_putchar('\n');
	free(nstr);
	return (num_char);
}
