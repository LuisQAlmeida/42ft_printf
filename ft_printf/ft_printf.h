
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_putchar_a(const char c);
int	ft_putstr_a(const char *s);
int	ft_putnum(long long nbr, const char c);
int	ft_print_format(const char c, va_list arg_list);
#endif
