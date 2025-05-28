
#include "ft_printf.h"

int	ft_putchar_adptd(const char c)
{
	return(write(1, &c, 1));
}

int	ft_putstr_adptd(const char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr_base_adptd(unsigned long long num, char format)
{
	char	*base;
	int		base_len;
	int		print_len = 0;
	if (format == 'p')
		void *ptr = va_arg(arg_list, void *);
		if (!ptr)
			print_len += ft_putstr_adptd("(nil)");
		print_len += ft_putstr_adptd("0x");
	if (format == 'X')
		base = "0123456789ABCDEF";
	if (format == 'x')
		base = "0123456789abcdef";
	if (format == 'd' || format == 'i' || format == 'u')
		base_len = 10;
	else
		base_len = 16;
	if (format == 'd' || format == 'i') {
		int n = (int)num;
		if (n < 0) {
			print_len += ft_putchar_adptd('-');
			num = -(long)n;
		}
	}
	if (num >= (unsigned long long)base_len)
		print_len += ft_putnbr_base_adptd(num / base_len, format);
	print_len += ft_putchar_adptd(base[num % base_len]);
	return (print_len);
}
