/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 16:55:10 by nieyraud          #+#    #+#             */
/*   Updated: 2019/11/09 17:11:36 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_parse_string(char *flags, va_list ap)
{
	t_flags p;

	ft_init_parse(&p);
	p.pad_zero = *flags == '0' ? 1 : 0;
	while (*flags == '0' || *flags == ' ')
		flags++;
	p.minus = *flags == '-' ? 1 : 0;
	while (*flags == '0' || *flags == ' ' || *flags == '-')
		flags++;
	p.pad_value = *flags == '*' ? ft_get_number('*', &p, ap) : ft_atoi(flags);
	while (*flags == '*' || (*flags >= '0' && *flags <= '9'))
		flags++;
	if (*flags == '.')
	{
		p.precision = 1;
		flags++;
	}
	if (*flags == '*')
		p.prec_len = ft_get_number('.', &p, ap);
	else
		p.prec_len = ft_atoi(flags);
	while (*flags == '*' || (*flags >= '0' && *flags <= '9'))
		flags++;
	return (ft_printstr(ap, p, 0));
}
