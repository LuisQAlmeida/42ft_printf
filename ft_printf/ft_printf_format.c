#include "ft_printf.h"

int	ft_print_format(const char c, va_list arg_list)
{
	if (c == 'c')
		return (ft_putchar_a(va_arg(arg_list, int)));
	else if (c == 's')
		return (ft_putstr_a(va_arg(arg_list, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnum(va_arg(arg_list, int), 'i'));
	else if (c == 'u')
		return (ft_putnum(va_arg(arg_list, unsigned int), 'u'));
	else if (c == 'x')
		return (ft_putnum(va_arg(arg_list, unsigned int), 'x'));
	else if (c == 'X')
		return (ft_putnum(va_arg(arg_list, unsigned int), 'X'));
	else if (c == 'p')
		return (ft_putnum((unsigned int)va_arg(arg_list, void *), 'p'));
	else if (c == '%')
		return (ft_putchar_a('%'));
	else
		return (ft_putchar_a(c));
}
