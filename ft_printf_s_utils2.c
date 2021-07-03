/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbertill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 11:50:34 by dbertill          #+#    #+#             */
/*   Updated: 2021/07/03 11:50:42 by dbertill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_s_null_fpoint(t_flags *flags)
{
	char	*s;
	char	*n;

	n = "(null)";
	if (flags->precision > 6 || flags->precision < -1)
		flags->precision = 6;
	if (flags->precision > flags->width)
	{
		flags->width = flags->precision;
		s = ft_calloc(flags->precision);
	}
	else
		s = ft_calloc(flags->width);
	return (ft_s_null_fpoint_2(flags, s, n));
}
