
#include "libftprintf.h"
#include <unistd.h>
#include <stdarg.h>

int	ft_printf(const char *format, ...)
{
	int		print_len;
	va_list	arg_list;

	print_len = 0;
	va_start(arg_list, format);
	if (!format)
	{
		write(1, "(null)", 6);
		return (-1);
	}
	while (*format)
	{
		if (*format == '%')
		{
			format++;
		}
		else
		{
			write(1, format, 1);
			print_len++;
		}
		format++;
	}
	va_end(arg_list);
	return (print_len);
}

int	main(void)
{
	return (ft_printf(0));
}

/*
- Create helper functions to print:
	- maybe use adapted ft_putnbr_base for p, d, i, u, x and X...
		- For p, if we pass a NULL pointer, it should print "(nill)"
		- For s, if we pass aNULL str, it should print "(null)"
	- use write for c
	- use ft_putstr for s
- Create helper function to check what comes after %
	- if it's a flag ('+', ' ' or '#') ->
	- if it's a '-' or a number -> check next idexes until there are no more numbers..
		- save the number in order to print the correct amount of spaces.
	- if it's a '.' -> check next indexes for nothing or for numbers until """""..
		- save the """""".
	- if it's cspdiuxX% use funstions to print (ft_putstr, ft_putnbr...)
*/
