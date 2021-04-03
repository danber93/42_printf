#include "ft_printf.h"


int		ft_handle_format(char f, t_flags *flags, va_list ap)
{
	if (f == 'c')
		return (ft_printf_c(va_arg(ap, int)));
	if (f == 'd' || f == 'i')
		return (ft_printf_i(va_arg(ap, int), flags, "0123456789"));
	if (f == 's')
		return (ft_printf_s(va_arg(ap, char *), flags));
	if (f == 'x')
		return (ft_printf_i(va_arg(ap, int), flags, "0123456789abcdef"));
	if (f == 'X')
		return (ft_printf_i(va_arg(ap, int), flags, "0123456789ABCDEF"));
	return (0);
}

