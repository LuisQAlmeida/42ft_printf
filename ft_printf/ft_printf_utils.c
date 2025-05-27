
#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

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

int	ft_itoa_base_adptd(const char *s, char c)
{

}

int	ft_putaddress(cons char *s)
{

}
