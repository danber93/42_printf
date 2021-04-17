#include "ft_printf.h"

int		ft_c_padding_right(char c, t_flags *flags)
{
	int		i;
	char	*s;

	s = ft_calloc(flags->width + 1);
	if (!s)
		return (-1);
	write(1, &c, 1);
	i = 0;
	while (i < flags->width - 1)
		s[i++] = ' ';
	return(1 + ft_result(s));
}

int		ft_c_padding_left(char c, t_flags *flags)
{
	int		i;
	char	*s;
	int		plusOne;

	s = ft_calloc(flags->width + 1);
	if (!s)
		return (-1);
	i = 0;
	while (i < flags->width - 1)
		s[i++] = ' ';
	s[i] = c;
	plusOne = 0;
	if (s[i] == '\x00')
		plusOne = 1;
	if (plusOne)
	{
		plusOne = ft_result(s);
		write(1, &s[i], 1);
		return(1 + plusOne);
	}
	return (ft_result(s));
}

int		ft_printf_c(char c, t_flags *flags)
{
	if (flags->width <= 1)
		return (ft_putchar(c));
	if (flags->minus)
		return (ft_c_padding_right(c , flags));
	return (ft_c_padding_left(c , flags));
}