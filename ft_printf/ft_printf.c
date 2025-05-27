
#include "ft_printf.h"
#include <unistd.h>
#include <stdarg.h>

int	ft_printf(const char *format, ...)
{
	int		print_len;
	va_list	arg_list;

	print_len = 0;
	va_start(arg_list, format);
	if (!format)
		return (-1);
	while (*format)
	{
		if (*format != '%')
			print_len += ft_putchar_adptd(*format);
		else
		{
			format++;
			print_len += ft_print_format(*format, arg_list);
		}
		format++;
	}
	va_end(arg_list);
	return (print_len);
}
