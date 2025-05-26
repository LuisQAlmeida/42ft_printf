
#include "ft_printf.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int     ft_putchar_adptd(const char c)
{
        return(write(1, &c, 1));
}

int	ft_printf(const char *format, ...)
{
	int		print_len;
	va_list	arg_list;

	print_len = 0;
	va_start(arg_list, format);
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

int	main(void)
{
	int	return_val;

	return_val = ft_printf("Hello\n");
	printf("%d\n", return_val);
	return (0);
}
