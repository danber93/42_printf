#include "ft_printf.h"

int		ft_blanks(char *s, t_flags *flags)
{
	// char	*tmp;
	// int		len;
	// int i;

	// i = 0;
	// if (flags->minus)
	// {
	// 	if (!(tmp = (char *)malloc(sizeof(char) * (flags->width + 1))))
	// 		return (-1);
	// 	while (i < (flags->width - (flags->width - flags->precision) - ft_stlren(s))
	// }
	return (0);
}

int		ft_print_i(int n, t_flags *flags)
{
	char	*s;

	s = ft_itoa_base(n, "0123456789");
	if (!flags->minus && (!flags->point && flags->precision < ft_strlen(s)))
	{
		flags->point = 0;
		return (ft_print_s(s, flags));
	}
	// if (flags->precision < flags->width)
	// {
	// 	return (ft_blanks(s, flags));
	// }
	if (flags->precision > flags->width)
	{
		flags->width = flags->precision;
		flags->point = 0;
		flags->zero = 1;
		// print_flags(flags);
		return (ft_print_s(s, flags));
	}
	else
	{
		flags->point = 0;
		return (ft_print_s(s, flags));
	}
	

	return (0);
}