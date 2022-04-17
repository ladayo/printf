#include "main.h"
/**
 * _printf - prints to stdout
 * @format: string of chars
 * Return: On success, number of characters
 **/
int _printf(const char *format, ...)
{
	int i = 0, j = 0, k = 0, len;
	char *dest, *str;
	va_list ap;

	va_start(ap, format);
	dest = malloc(sizeof(char) * 1500);
	if (dest == NULL)
		return (1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 's')
			{
				str = va_arg(ap, char*);
				while (str[k])
				{
					dest[j] = str[k];
					k++;
					j++;
				}
			}
			else if (format[i] == 'c')
			{
				dest[j] = (char)va_arg(ap, int);
				j++;
			}
		}
		else
		{
			dest[j] = format[i];
			j++;
		}
		i++;
	}
	len = _sprint(dest);
	free(dest);
	va_end(ap);
	return (len);
}
