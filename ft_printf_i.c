#include "ft_printf.h"

// int		ft_blanks(char *s, t_flags *flags)
// {
// 	// char	*tmp;
// 	// int		len;
// 	// int i;

// 	// i = 0;
// 	// if (flags->minus)
// 	// {
// 	// 	if (!(tmp = (char *)malloc(sizeof(char) * (flags->width + 1))))
// 	// 		return (-1);
// 	// 	while (i < (flags->width - (flags->width - flags->precision) - ft_stlren(s))
// 	// }
// 	return (0);
// }

// int		ft_printf_i(int n, t_flags *flags)
// {
// 	char	*s;

// 	s = ft_itoa_base(n, "0123456789");
// 	if (!flags->minus && (!flags->point && flags->precision < ft_strlen(s)))
// 	{
// 		flags->point = 0;
// 		return (ft_printf_s(s, flags));
// 	}
// 	// if (flags->precision < flags->width)
// 	// {
// 	// 	return (ft_blanks(s, flags));
// 	// }
// 	if (flags->precision > flags->width)
// 	{
// 		flags->width = flags->precision;
// 		flags->point = 0;
// 		flags->zero = 1;
// 		// print_flags(flags);
// 		return (ft_printf_s(s, flags));
// 	}
// 	else
// 	{
// 		flags->point = 0;
// 		return (ft_printf_s(s, flags));
// 	}
	

// 	return (0);
// }

int		ft_i_padding_left(char *s, t_flags *flags)
{
	int		i;
	int		padding;
	char	*dest;

	if (!(dest = ft_calloc(dest, flags->precision)))
		return (-1);
	padding = flags->precision - ft_strlen(s);
	i = 0;
	while (i < padding)
		dest[i++] = '0';
	while (i < flags->precision)
	{
		dest[i] = s[i - padding];
		i++;
	}
	dest[i] = '\0';
	return (ft_putstr(dest));
}

int		ft_i_padding_blanks_left(char *s, t_flags *flags)
{
	int		i;
	int		zeros;
	int		blanks;
	char	*dest;

	if (!(dest = ft_calloc(dest, flags->width)))
		return (-1);
	if ((zeros = flags->precision - ft_strlen(s)) < 0)
		zeros = 0;
	blanks = flags->width - ft_strlen(s) - zeros;
	i = 0;
	while (i < blanks)
		dest[i++] = ' ';
	while (i < blanks + zeros)
		dest[i++] = '0';
	while (i < flags->width)
	{
		dest[i] = s[i - blanks - zeros];
		i++;
	}
	dest[i] = '\0';
	return (ft_putstr(dest));
}

int		ft_i_padding_blanks_right(char *s, t_flags *flags)
{
	int		i;
	int		len;
	int		zeros;
	int		blanks;
	char	*dest;

	if (!(dest = ft_calloc(dest, flags->width)))
		return (-1);
	len = ft_strlen(s);
	if ((zeros = flags->precision - len) < 0)
		zeros = 0;
	blanks = flags->width - len - zeros;
	i = 0;
	while (i < zeros)
		dest[i++] = '0';
	while (i < zeros + len)
	{
		dest[i] = s[i - zeros];
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

	// print_flags(flags);
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