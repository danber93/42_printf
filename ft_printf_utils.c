#include "ft_printf.h"


int		ft_handle_format(char f, t_flags *flags, va_list ap)
{
	if (f == 'c')
		return (ft_printf_c(va_arg(ap, int)));
	if (f == 'd' || f == 'i')
		return (ft_printf_i(va_arg(ap, int), flags));
	if (f == 's')
		return (ft_printf_s(va_arg(ap, char *), flags));
	return (0);
}

