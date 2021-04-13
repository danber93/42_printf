#include "ft_printf.h"

int		ft_result(char *s)
{
	int	i;

	i = ft_putstr(s);
	free(s);
	return (i);
}

int		ft_handle_format(char f, t_flags *flags, va_list ap)
{
	if (f == 'c')
		return (ft_printf_c(va_arg(ap, int), flags));
	if (f == 'd' || f == 'i')
		return (ft_printf_i(va_arg(ap, int), flags, "0123456789"));
	if (f == 's')
		return (ft_printf_s(va_arg(ap, char *), flags));
	if (f == 'x')
		return (ft_printf_x(va_arg(ap, long int), flags, "0123456789abcdef"));
	if (f == 'X')
		return (ft_printf_x(va_arg(ap, long int), flags, "0123456789ABCDEF"));
	if (f == 'p')
		return (ft_printf_p(va_arg(ap, long int), flags, "0123456789abcdef"));
	if (f == 'u')
		return (ft_printf_u(va_arg(ap, unsigned int), flags, "0123456789"));
	return (0);
}

