#include "ft_printf.h"

int		ft_i_padding_left(char *s, t_flags *flags)
{
	int		i;
	int		j;
	int		padding;
	char	*dest;

	// if (ft_strlen(s) == 1 && (flags->width > ft_strlen(s) || flags->precision > ft_strlen(s)))
	// 	if (s[0] == '0')
	// 		s[0] = ' ';
	dest = ft_calloc(flags->precision + ft_is_neg(s));
	if (!dest)
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
	free(s);
	return (ft_result(dest));
}

char	*ft_cut_minus(char *s)
{
	int		i;
	int		j;
	int		len;
	char	*dest;

	len = ft_strlen(s);
	dest = ft_calloc(len);
	if (!dest)
		return (NULL);
	i = 1;
	j = 0;
	while (s[i])
		dest[j++] = s[i++];
	free(s);
	return (dest);
}

int		ft_i_pleft_no_blanks(char *s, char *dest, int zeros)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (ft_is_neg(s))
		dest[i++] = s[j++];
	while (i < zeros + ft_is_neg(s))
		dest[i++] = '0';
	while (i < zeros + ft_strlen(s))
		dest[i++] = s[j++];
	free(s);
	return (ft_result(dest));
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
	zeros = 0;
	if (flags->precision > ft_strlen(s))
	{
		zeros = flags->precision - ft_strlen(s) + ft_is_neg(s);
		blanks = flags->width - zeros - ft_strlen(s);	
	}
	else
	{
		blanks = flags->width - ft_strlen(s);
		if (flags->zero && !flags->point)
		{
			zeros = blanks;
			blanks = 0;
		}
	}
	i = 0;
	j = 0;
	if (blanks == 0)
		return (ft_i_pleft_no_blanks(s, dest, zeros));
	while (i < blanks)
		dest[i++] = ' ';
	if (ft_is_neg(s))
		dest[i++] = s[j++];
	while (i < blanks + zeros + ft_is_neg(s))
		dest[i++] = '0';
	if (ft_strlen(s) == 1 && s[0] == '0' && flags->point == 1 && flags->precision <= 0)
		s[0] = ' ';
	while (i < blanks + zeros + ft_strlen(s))
		dest[i++] = s[j++];
	free(s);
	return (ft_result(dest));
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
	char	*dest;

	if (!(dest = ft_calloc(flags->width)))
		return (-1);
	i = 0;
	if (s[0] == '-')
		dest[i++] = '-';
	if (ft_strlen(s) == 1 && s[0] == '0' && flags->point == 1 && flags->precision <= 0)
		s[0] = ' ';
	if ((zeros = flags->precision - ft_strlen(s) + ft_is_neg(s)) < 0)
		zeros = 0;
	while (i < zeros + ft_is_neg(s))
		dest[i++] = '0';
	while (i < zeros + ft_strlen(s))
	{
		dest[i] = s[i - zeros];
		i++;
	}
	while (i < flags->width)
		dest[i++] = ' ';
	free(s);
	return (ft_result(dest));
}

int		ft_printf_i(int n, t_flags *flags, char *base)
{
	char	*s;

	s = ft_itoa_base(n, base);
	if (!(flags->point) && !(flags->width))
		return (ft_result(s));
	if (flags->precision >= flags->width)
	{
		if (flags->precision <= ft_strlen(s))
		{
			if (flags->precision <= 0 && s[0] == '0')
			{
				free(s);
				return (0);
			}
			else
				return (ft_result(s));
		}
		return (ft_i_padding_left(s, flags));
	}
	if (flags->width > flags->precision)
	{
		if (flags->width == 0 && flags->precision == -1 && s[0] == '0')
		{
			free(s);
			return (0);
		}
		if (flags->width <= ft_strlen(s))
		{
			if (ft_strlen(s) == 1)
				if (s[0] == '0')
					s[0] = ' ';
			return (ft_result(s));
		}
		if (!flags->minus)
			return (ft_i_padding_blanks_left(s, flags));
		return (ft_i_padding_blanks_right(s, flags));
	}
	return (0);
}