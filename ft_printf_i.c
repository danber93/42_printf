#include "ft_printf.h"

int		ft_i_padding_left(char *s, t_flags *flags)
{
	int		i;
	int		j;
	int		padding;
	int		neg;
	char	*dest;

	neg = 0;
	if (s[0] == '-')
		neg = 1;
	if (!(dest = ft_calloc(flags->precision + neg)))
		return (-1);
	i = 0;
	if (neg)
	{
		dest[i++] = '-';
		s = ft_cut_minus(s);
	}
	padding = flags->precision - ft_strlen(s) + neg;
	while (i < padding)
		dest[i++] = '0';
	j = 0;
	while (i < flags->precision + neg)
	{
		if (s[j] == '-')
			j++;
		else
			dest[i++] = s[j++];
	}
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
	int		neg;

	if (!(dest = ft_calloc(flags->width)))
		return (-1);
	neg = 0;
	if (s[0] == '-')
	{
		neg = 1;
		s = ft_cut_minus(s);
	}
	if ((zeros = flags->precision - ft_strlen(s)) < 0)
		zeros = 0;
	blanks = flags->width - ft_strlen(s) - zeros;
	i = 0;
	while (i < blanks - neg)
		dest[i++] = ' ';
	if (neg)
		dest[i++] = '-';
	while (i < blanks + zeros)
		dest[i++] = '0';
	while (i < flags->width)
	{
		dest[i] = s[i - blanks - zeros];
		i++;
	}
	return (ft_putstr(dest));
}

int		ft_i_padding_blanks_right(char *s, t_flags *flags)
{
	int		i;
	int		len;
	int		zeros;
	int		blanks;
	char	*dest;
	int		neg;

	if (!(dest = ft_calloc(flags->width)))
		return (-1);
	i = 0;
	neg = 0;
	if (s[0] == '-')
	{
		neg = 1;
		dest[i++] = '-';
		s = ft_cut_minus(s);
	}
	len = ft_strlen(s);
	if ((zeros = flags->precision - len + neg) < 0)
		zeros = 0;
	blanks = flags->width - len - zeros;
	while (i < zeros - neg)
		dest[i++] = '0';
	while (i < zeros + len + neg)
	{
		dest[i] = s[i - zeros - neg];
		i++;
	}
	while (i < flags->width)
		dest[i++] = ' ';
	dest[i] = '\0';
	return (ft_putstr(dest));
}

int		ft_printf_i(int n, t_flags *flags)
{
	char	*s;

	s = ft_itoa_base(n, "0123456789");
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