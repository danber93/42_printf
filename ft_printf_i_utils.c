/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_i_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbertill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:58:30 by dbertill          #+#    #+#             */
/*   Updated: 2021/05/08 15:58:31 by dbertill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_i_padding_left(char *s, t_flags *flags)
{
	int		i;
	int		j;
	int		padding;
	char	*dest;

	dest = ft_calloc(flags->precision + ft_is_neg(s));
	if (!dest)
		return (-1);
	i = 0;
	if (ft_is_neg(s))
		dest[i++] = '-';
	padding = flags->precision - ft_strlen(s) + ft_is_neg(s);
	while (i < padding + ft_is_neg(s))
		dest[i++] = '0';
	j = 0 + ft_is_neg(s);
	while (i < flags->precision + ft_is_neg(s))
		dest[i++] = s[j++];
	free(s);
	return (ft_result(dest));
}

char	*ft_cut_minus(char *s)
{
	int		i;
	int		j;
	int		len;
	char	*dest;

	len = ft_strlen(s);
	dest = ft_calloc(len);
	if (!dest)
		return (NULL);
	i = 1;
	j = 0;
	while (s[i])
		dest[j++] = s[i++];
	free(s);
	return (dest);
}

int	ft_i_pleft_no_blanks(char *s, char *dest, int zeros)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (ft_is_neg(s))
		dest[i++] = s[j++];
	while (i < zeros + ft_is_neg(s))
		dest[i++] = '0';
	while (i < zeros + ft_strlen(s))
		dest[i++] = s[j++];
	free(s);
	return (ft_result(dest));
}

int	ft_i_padding_blanks_left_2(char *s, t_flags *flags, int blanks, int zeros)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	dest = ft_calloc(flags->width);
	if (!dest)
		return (-1);
	if (blanks == 0)
		return (ft_i_pleft_no_blanks(s, dest, zeros));
	while (i < blanks)
		dest[i++] = ' ';
	if (ft_is_neg(s))
		dest[i++] = s[j++];
	while (i < blanks + zeros + ft_is_neg(s))
		dest[i++] = '0';
	if (ft_strlen(s) == 1 && s[0] == '0' && flags->point == 1
		&& flags->precision <= 0)
		s[0] = ' ';
	while (i < blanks + zeros + ft_strlen(s))
		dest[i++] = s[j++];
	free(s);
	return (ft_result(dest));
}

int	ft_is_neg(char *s)
{
	if (s[0] == '-')
		return (1);
	return (0);
}
