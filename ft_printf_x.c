#include "ft_printf.h"

int		ft_x_padding_left(char *s, t_flags *flags)
{
	char	*dest;
	int		i;
	int		len;
	int		j;

	dest = ft_calloc(flags->width + 1);
	len = ft_strlen(s);
	i = 0;
	while (i < flags->width - len)
		dest[i++] = '0';
	j = 0;
	while (i < flags->width)
		dest[i++] = s[j++];
	free(s);
	return (ft_result(dest));
}

int		ft_printf_x(long int n, t_flags *flags, char *base)
{
	char	*s;

	s = ft_itoa_base_u(n, base);
	if (flags->zero)
		return (ft_x_padding_left(s, flags));
	if (!(flags->point) && !(flags->width))
		return (ft_result(s));
	if (flags->precision >= flags->width)
	{
		if (flags->precision <= ft_strlen(s))
			return (ft_result(s));
		return (ft_i_padding_left(s, flags));
	}
	if (flags->width > flags->precision)
	{
		if (flags->width <= ft_strlen(s))
			return (ft_result(s));
		if (!flags->minus)
			return (ft_i_padding_blanks_left(s, flags));
		return (ft_i_padding_blanks_right(s, flags));
	}
	return (0);
}