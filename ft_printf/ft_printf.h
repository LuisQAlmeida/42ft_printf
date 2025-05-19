
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
size_t	ft_strlen(const char *s);
void	ft_putchar(char c);
void	ft_putstr(char *s);
#endif
