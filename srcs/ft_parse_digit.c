/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 23:25:36 by nieyraud          #+#    #+#             */
/*   Updated: 2019/11/04 05:52:24 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int		ft_parse_flags(t_flags *p, char *flags, va_list ap)
{
	if (*flags == '0')
		return (p->pad_zero = 1);
	if (*flags == ' ')
		return (p->space = 1);
	if (*flags == '-')
		return (p->minus = 1);
	if (*flags == '+')
		return (p->plus = 1);
	if (!p->pad_value && ((*flags > '0' && *flags <= '9') || *flags == '*'))
	{
		if (*flags == '*')
			p->pad_value = va_arg(ap, int);
		else
			p->pad_value = ft_atoi(flags);
		return (*flags == '*' ? 1 : int_length(p->pad_value));
	}
	return (0);
}

int				ft_parse_digit(char *flags, va_list ap)
{
	t_flags p;
	int		nbr;

	ft_init_parse(&p);
	while (ft_isalpha(*flags) == 0)
	{
		flags = flags + ft_parse_flags(&p, flags, ap);
		if (*flags == '.')
		{
			p.precision = 1;
			flags++;
			p.prec_len = *flags == '*' ? va_arg(ap, int) : ft_atoi(flags);
			while (*flags == '*' || (*flags > '0' && *flags <= '9'))
				flags++;
		}
	}
	p.pad_zero = p.precision == 1 ? 0 : p.pad_zero;
	nbr = va_arg(ap, int);
	if (p.pad_value > 0 && p.plus == 1 && nbr > 0)
		p.pad_value--;
	return (ft_printnbr(p, nbr));
}
