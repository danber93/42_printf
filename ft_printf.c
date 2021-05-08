#include "ft_printf.h"

int	ft_is_flag(char c, t_flags *flags, va_list ap)
{
	if (c == 'd' || c == 'i' || c == 'c' || c == 's' || c == 'p'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (0);
	if (flags->width == 0 && flags->point == 0 && c == '0')
		flags->zero = 1;
	if (c == '-')
		flags->minus = 1;
	if (c == '.')
		flags->point = 1;
	if (c == '*')
		ft_flags_star(flags, ap);
	if (c >= '0' && c <= '9')
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

int	ft_read_input_continue(const char *s, va_list ap, int res, t_flags *flags)
{
	int	i;
	int	f;

	i = 0;
	f = 0;
	while (s[i])
	{
		if (!f && s[i] != '%')
			res += ft_putchar(s[i]);
		else if (f == 1)
		{
			while (ft_is_flag(s[i], flags, ap))
				i++;
			res += ft_handle_format(s[i], flags, ap);
			f = 0;
			ft_flags_init(flags);
		}
		else if (s[i] == '%' && s[i + 1] == '%')
			res += ft_putchar(s[++i]);
		else if (s[i] == '%' && s[i + 1] != '%')
			f = 1;
		i++;
	}
	return (res);
}

int	ft_read_input(const char *s, va_list ap)
{
	t_flags	flags;
	int		res;

	ft_flags_init(&flags);
	res = 0;
	return (ft_read_input_continue(s, ap, res, &flags));
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		res;

	res = 0;
	va_start(ap, s);
	res = ft_read_input(s, ap);
	va_end(ap);
	return (res);
}
