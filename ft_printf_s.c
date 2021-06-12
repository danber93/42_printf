/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbertill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 16:00:08 by dbertill          #+#    #+#             */
/*   Updated: 2021/05/08 16:00:09 by dbertill         ###   ########.fr       */
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

int	ft_s_null_pleft(t_flags *flags)
{
	int		i;
	int		j;
	char	*s;
	char	*n;

	n = "(null)";
	if (!flags->width && !flags->point)
		return (ft_putstr(n));
	if (flags->point == 1)
		return (ft_s_null_fpoint(flags));
	if (flags->minus)
		return (ft_s_null_pright(flags));
	i = 0;
	j = 0;
	if (flags->width > ft_strlen(n))
		s = ft_calloc(flags->width);
	else
		s = ft_calloc(ft_strlen(n));
	if (flags->width > 0)
	{
		if (ft_strlen(n) > flags->width)
			flags->width = ft_strlen(n);
		while (i < flags->width - ft_strlen(n))
			s[i++] = ' ';
		while (i < flags->width)
			s[i++] = n[j++];
	}
	return (ft_result(s));
}

int	ft_printf_s_3(t_flags *flags, char *t)
{
	if (flags->width != 0)
	{
		if (flags->width > ft_strlen(t))
		{
			t = ft_s_padding(t, flags);
			if (!t)
				return (-1);
		}
	}
	return (ft_result(t));
}

int	ft_printf_s_2(char *s, t_flags *flags, char *t, int len)
{
	if (flags->point == 1 && (flags->precision > -1 || (flags->star_precision == 0 && flags->precision == -1)))
	{
		if (flags->precision < len)
		{
			t = ft_strndup(s, t, flags->precision);
			if (!t)
				return (-1);
		}
		else
		{
			t = ft_strndup(s, t, len);
			if (!t)
				return (-1);
		}
	}
	else
		t = ft_strndup(s, t, ft_strlen(s));
	return (ft_printf_s_3(flags, t));
}

int	ft_printf_s(char *s, t_flags *flags)
{
	int		len;
	char	*t;

	if (flags->width < 0)
	{
		flags->minus = 1;
		flags->width *= -1;
	}
	if (flags->precision < -1 && s)
		flags->precision = ft_strlen(s);
	if (!s)
		return (ft_s_null_pleft(flags));
	if (!(flags->point) && !(flags->width))
		return (ft_putstr(s));
	len = ft_strlen(s);
	t = ft_calloc(1);
	return (ft_printf_s_2(s, flags, t, len));
}
