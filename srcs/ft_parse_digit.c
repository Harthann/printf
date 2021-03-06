/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 23:25:36 by nieyraud          #+#    #+#             */
/*   Updated: 2019/11/14 14:44:45 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				ft_parse_flags(t_flags *p, char *flags, va_list ap)
{
	if (*flags == '0')
		return (p->pad_zero = 1);
	if (*flags == '-')
		return (p->minus = 1);
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
	p.pad_zero = *flags == '0';
	while (*flags == '0')
		flags++;
	p.minus = *flags == '-';
	while (*flags == '-')
		flags++;
	p.pad_value = *flags == '*' ? get_number('*', &p, ap, 'd') : ft_atoi(flags);
	while ((*flags >= '0' && *flags <= '9') || *flags == '*')
		flags++;
	p.precision = *flags == '.';
	while (*flags == '.')
		flags++;
	p.prec_len = *flags == '*' ? get_number('.', &p, ap, 's') : ft_atoi(flags);
	nbr = va_arg(ap, int);
	p.pad_zero = p.precision == 1 && !nbr && !p.prec_len ? 0 : p.pad_zero;
	return (ft_printnbr(p, nbr));
}
