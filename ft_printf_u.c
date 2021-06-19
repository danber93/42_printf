/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbertill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:59:00 by dbertill          #+#    #+#             */
/*   Updated: 2021/05/08 15:59:01 by dbertill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_u(unsigned int n, t_flags *flags, char *base)
{
	char	*s;

	s = ft_itoa_base_u(n, base);
	if (ft_strlen(s) == 1)
		if (s[0] == '0' && (!flags->precision || (flags->point == 1 && flags->precision == -1 && flags->star_precision == 0)))
			s[0] = '\0';
	if (!(flags->point) && !(flags->width))
		return (ft_result(s));
	if (flags->precision >= flags->width)
	{
		if (flags->precision <= ft_strlen(s))
			return (ft_result(s));
		return (ft_i_padding_left(s, flags));
	}
	if (flags->width > flags->precision)
	{
		if (flags->width <= ft_strlen(s))
			return (ft_result(s));
		if (!flags->minus)
			return (ft_i_padding_blanks_left(s, flags));
		return (ft_i_padding_blanks_right(s, flags));
	}
	return (0);
}
