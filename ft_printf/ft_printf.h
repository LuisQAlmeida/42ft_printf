
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_putchar_adptd(const char c);
int	ft_putstr_adptd(const char *s);
int	ft_putnbr_base_adptd(const char *s, const char c);
int	ft_print_format(const char c, va_list arg_list);
#endif
