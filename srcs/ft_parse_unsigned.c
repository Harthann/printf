/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:56:11 by nieyraud          #+#    #+#             */
/*   Updated: 2019/11/09 17:19:07 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_parse_unsigned(char *flags, va_list ap)
{
	t_flags p;

	ft_init_parse(&p);
	p.pad_zero = *flags == '0';
	while (*flags == '0')
		flags++;
	p.minus = *flags == '-';
	while (*flags == '-')
		flags++;
	p.pad_value = *flags == '*' ? ft_get_number('*', &p, ap) : ft_atoi(flags);
	while ((*flags >= '0' && *flags <= '9') || *flags == '*')
		flags++;
	p.precision = *flags == '.';
	while (*flags == '.')
		flags++;
	p.prec_len = *flags == '*' ? ft_get_number('.', &p, ap) : ft_atoi(flags);
	return (ft_print_unsigned(p, va_arg(ap, unsigned int)));
}
