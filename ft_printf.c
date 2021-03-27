#include "ft_printf.h"

void		ft_flags_star(char c, t_flags *flags, va_list ap)
{
	// printf("sto sborrando\n");
	if (!flags->point)
	{
		flags->star_width = 1;
		flags->width = va_arg(ap, int);
	}
	else
	{
		flags->star_precision = 1;
		flags->precision = va_arg(ap, int);
	}
}

int		ft_is_flag(char c, t_flags *flags, va_list ap)
{
	if (c == 'd' || c == 'i' || c == 'c' || c == 's' || c == 'p' ||
	c == 'u' || c == 'x' || c == 'X')
		return (0);
	if (c == '0')
		flags->zero = 1;
	if (c == '-')
		flags->minus = 1;
	if (c == '.')
		flags->point = 1;
	if (c == '*')
		ft_flags_star(c, flags, ap);
	if (c >= '1' && c <= '9')
	{
		if (!(flags->point))
			flags->width = flags->width * 10 + (c - '0');
		else 
		{
			if (flags->precision == -1)
				flags->precision = 0 + (c - '0');
			else
				flags->precision = flags->precision * 10 + (c - '0');
		}
	}
	// print_flags(flags);
	return (1);
}

void	ft_flags_init(t_flags *flags)
{
	flags->zero = 0;
	flags->minus = 0;
	flags->point = 0;
	flags->star_width = 0;
	flags->star_precision = 0;
	flags->precision = -1;
	flags->width = 0;
}

void	print_flags(t_flags *flags)
{
	printf("\n\n-----------------------------------------------\n");
	printf("                                               \n");
	printf("Zero = %d\n", flags->zero);
	printf("Minus = %d\n", flags->minus);
	printf("Star_Width = %d\n", flags->star_width);
	printf("Star_Precision = %d\n", flags->star_precision);
	printf("Point = %d\n", flags->point);
	printf("Width = %d\n", flags->width);
	printf("Precision = %d\n", flags->precision);
	printf("                                               \n");
	printf("-----------------------------------------------\n\n");
}

int		ft_read_input(const char *s, va_list ap)
{
	t_flags flags;
	int		i;
	int		res;
	int		f;

	ft_flags_init(&flags);
	i = 0;
	f = 0;
	res = 0;
	while (s[i])
	{
		if (!f && s[i] != '%')
			res += ft_putchar(s[i]); //ritorna sempre 1
		else if (f == 1)
		{
			while (ft_is_flag(s[i], &flags, ap))
				i++;
			res += ft_handle_format(s[i], &flags, ap);
			f = 0;		//fine sottostringa flag+codifica
			ft_flags_init(&flags);
		}
		else if (s[i] == '%' && s[i+1] == '%')
		{
			i++;
			res += ft_putchar(s[i]);
		}
		else if (s[i] == '%' && s[i + 1] != '%')
			f = 1;
		i++;
	}
	// print_flags(&flags);
	return (res);
}

int		ft_printf(const char *s, ...)
{
	va_list ap;
	int		res;

	res = 0;
	va_start(ap, s);
	res = ft_read_input(s, ap);
	va_end(ap);
	return (res);
}
