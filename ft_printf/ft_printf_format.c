
#include "ft_printf.h"

int	ft_print_format(const char c, va_list arg_list)
{
	int	print_len;

	print_len = 0;
	if (c == 'c')
		print_len += ft_putchar_adptd(va_arg(arg_list, int));
	else if (c == 's')
		print_len += ft_putstr_adptd(va_arg(arg_list, char *));
	else if (c == 'd' || c == 'i')
		print_len += ft_putnbr_base_adptd(va_arg(arg_list, int), i);
	else if (c == 'u')
		print_len += ft_putnbr_base_adptd(va_arg(arg_list, unsigned int), u);
	else if (c == 'x')
		print_len += ft_putnbr_base_adptd(va_arg(arg_list, unsigned int), x);
	else if (c == 'X')
		print_len += ft_putnbr_base_adptd(va_arg(arg_list, unsigned int), X);
	else if (c == 'p')
		print_len += ft_putnbr_base_adptd((unsigned long)va_arg(arg_list, void *))
	else
		print_len += ft_putchar_adptd(c)
	return (print_len);
}
