#include "ft_printf.h"


int		ft_x_revert(char *dest, int blanks)
{
	int		i;
	int		j;
	char	*res;

	res = ft_calloc(ft_strlen(dest));
	i = 0;
	while (i < blanks)
		res[i++] = ' ';
	j = 0;
	while (i < ft_strlen(dest))
		res[i++] = dest[j++];
	free(dest);
	return (ft_result(res));
}

int		ft_x_padding_left_point(char *s, t_flags *flags)
{
	int		i;
	int		j;
	int		len;
	int		blanks;
	int		zeros;
	char	*dest;

	len = ft_strlen(s);
	
	if (flags->width < len)
	{
		if (flags->precision > len)
			flags->width = flags->precision;
		else
			flags->width = len;
	}
	if (flags->precision > len)
	{
		blanks = flags->width - flags->precision;
		zeros = flags->precision - len;
	}
	else
	{
		blanks = flags->width - len;
		zeros = 0;
	}
	dest = ft_calloc(flags->width);
	i = 0;
	while (i < blanks)
		dest[i++] = ' ';
	while (i < blanks + zeros)
		dest[i++] = '0';
	j = 0;
	while (i < flags->width)
		dest[i++] = s[j++];
	free(s);
	if (flags->minus)
		return (ft_x_revert(dest, blanks));
	return (ft_result(dest));
}

int		ft_x_padding_left(char *s, t_flags *flags)
{
	char	*dest;
	int		i;
	int		len;
	int		j;

	len = ft_strlen(s);
	if (flags->point)
		return (ft_x_padding_left_point(s, flags));
	if (flags->width < len)
		flags->width = len;
	dest = ft_calloc(flags->width + 1);
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
	if (flags->point && flags->precision <= 0 && ft_strlen(s) == 1)
		if (s[0] == '0' && !flags->star_precision)
			s[0] = '\0';
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