#include "ft_printf.h"

int		ft_i_padding_left(char *s, t_flags *flags)
{
	int		i;
	int		j;
	int		padding;
	char	*dest;

	if (!(dest = ft_calloc(flags->precision + ft_is_neg(s))))
		return (-1);
	i = 0;
	if (ft_is_neg(s))
		dest[i++] = '-';
	padding = flags->precision - ft_strlen(s) + ft_is_neg(s);
	while (i < padding + ft_is_neg(s))
		dest[i++] = '0';
	j = 0 + ft_is_neg(s);
	while (i < flags->precision + ft_is_neg(s))
			dest[i++] = s[j++];
	return (ft_putstr(dest));
}

char	*ft_cut_minus(char *s)
{
	int		i;
	int		j;
	int		len;
	char	*dest;

	len = ft_strlen(s);
	if (!(dest = ft_calloc(len)))
		return (NULL);
	i = 1;
	j = 0;
	while (s[i])
		dest[j++] = s[i++];
	return (dest);
}

int		ft_i_padding_blanks_left(char *s, t_flags *flags)
{
	int		i;
	int		zeros;
	int		blanks;
	char	*dest;
	int		j;

	if (!(dest = ft_calloc(flags->width)))
		return (-1);
	if ((zeros = flags->precision - ft_strlen(s) + ft_is_neg(s)) < 0)
		zeros = 0;
	if (flags->precision > ft_strlen(s) - ft_is_neg(s))
		blanks = flags->width - flags->precision;
	else
		blanks = flags->width - ft_strlen(s) + ft_is_neg(s);
	i = 0;
	while (i < blanks - ft_is_neg(s))
		dest[i++] = ' ';
	if (ft_is_neg(s))
		dest[i++] = '-';
	while ((i < blanks + zeros) && (zeros > 0))
		dest[i++] = '0';
	j = 0 + ft_is_neg(s);
	while (i < flags->width)
		dest[i++] = s[j++];
	return (ft_putstr(dest));
}

int		ft_is_neg(char *s)
{
	if (s[0] == '-')
		return (1);
	return (0);
}

int		ft_i_padding_blanks_right(char *s, t_flags *flags)
{
	int		i;
	int		zeros;
	int		blanks;
	char	*dest;

	if (!(dest = ft_calloc(flags->width)))
		return (-1);
	i = 0;
	if (s[0] == '-')
		dest[i++] = '-';
	if ((zeros = flags->precision - ft_strlen(s) + ft_is_neg(s)) < 0)
		zeros = 0;
	blanks = flags->width - flags->precision - ft_is_neg(s);
	while (i < zeros + ft_is_neg(s))
		dest[i++] = '0';
	while (i < zeros + ft_strlen(s))
	{
		dest[i] = s[i - zeros];
		i++;
	}
	while (i < flags->width)
		dest[i++] = ' ';
	return (ft_putstr(dest));
}

int		ft_printf_i(int n, t_flags *flags, char *base)
{
	char	*s;

	s = ft_itoa_base(n, base);
	if (!(flags->point) && !(flags->width))
		return (ft_putstr(s));
	if (flags->precision >= flags->width)
	{
		if (flags->precision <= ft_strlen(s))
			return (ft_putstr(s));
		return (ft_i_padding_left(s, flags));
	}
	if (flags->width > flags->precision)
	{
		if (flags->width <= ft_strlen(s))
			return (ft_putstr(s));
		if (!flags->minus)
			return (ft_i_padding_blanks_left(s, flags));
		return (ft_i_padding_blanks_right(s, flags));
	}
	return (0);
}