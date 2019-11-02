/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 23:25:36 by nieyraud          #+#    #+#             */
/*   Updated: 2019/11/02 04:34:47 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

static int		ft_parse_flags(t_flags *p, char flag)
{
	if (flag == '0')
		return (p->pad_zero = 1);
	if (flag == ' ')
		return (p->pad_space = 1);
	if (flag == '-')
		return (p->minus = 1);
	if (flag == '+')
		return (p->plus = 1);
	return (0);
}

int				ft_parse_digit(char *flags, va_list ap)
{
	t_flags p;

	ft_init_parse(&p);
	while (*flags)
	{
		ft_parse_flags(&p, *flags) ? flags++ : 0;
		if (*flags == '*')
			p.pad_value = va_arg(ap, int);
		else if (*flags > '0' && *flags < '9')
			p.pad_value = ft_atoi(flags);
		flags += (*flags > '0' && *flags < '9') ? int_length(p.pad_value) : 0;
		if (*flags == '.')
		{
			p.precision = 1;
			p.prec_len = *++flags == '*' ? va_arg(ap, int) : ft_atoi(flags++);
		}
	}
	printf("[%d]", p.pad_value);
	return (ft_printnbr(ap, p));
}
