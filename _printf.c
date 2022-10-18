#include "main.h"

/**
 * _printf - formatted output conversion and print data.
 * @format: input string.
 * Return: number of chars printed.
 */
int _printf(const char *format, ...)
{
	unsigned int i = 0, len = 0, ibuf = 0;
	va_list ptr;
	/* function that will be called when selcting function */
	int (*fpntr)(va_list, char *, unsigned int);
	char *buffer_size;

	va_start(ptr, format), buffer_size = malloc(sizeof(char) * 1024);
	if (!format || !buffer_size || (format[i] == '%' && !format[i + 1]))
		return (-1);

	if (!format[i])
		return (0);

	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')	/* if format specifier */
		{
			if (format[i + 1] == '\0')
			{	
				_putchar(buffer_size, ibuf);
				free(buffer_size);
				va_end(ptr);
				return (-1);
			}
			else
			{	
				fpntr = fpntr_func(format, i + 1);
				if (fpntr == NULL) /* if no suitable function is found */
				{
					if (format[i + 1] == ' ' && !format[i + 2])
						return (-1);
					handl_buf(buffer_size, format[i], ibuf), len++, i--;
				}
				else
				{
					len += fpntr(ptr, buffer_size, ibuf);
					i += number_of_ident(format, i + 1);
				}
			} i++;
		}
		else
			handl_buf(buffer_size, format[i], ibuf), len++;
		for (ibuf = len; ibuf > 1024; ibuf -= 1024)
			;
	}
	_putchar(buffer_size, ibuf);
	free(buffer_size);
	va_end(ptr);
	return (len);
}
