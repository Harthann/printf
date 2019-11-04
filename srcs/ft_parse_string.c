/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 20:44:24 by nieyraud          #+#    #+#             */
/*   Updated: 2019/11/03 03:18:53 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_parse_string(char *flags, va_list ap)
{
	t_flags parse;

	ft_init_parse(&parse);
	parse.pad_zero = *flags == '0' ? 1 : 0;
	while (*flags == '0' || *flags == ' ')
		flags++;
	parse.minus = *flags == '-' ? 1 : 0;
	while (*flags == '0' || *flags == ' ' || *flags == '-')
		flags++;
	parse.pad_value = *flags == '*' ? va_arg(ap, int) : ft_atoi(flags);
	while (*flags == '*' || (*flags >= '0' && *flags <= '9'))
		flags++;
	if (*flags == '.')
	{
		parse.precision = 1;
		flags++;
	}
	if (*flags == '*')
		parse.prec_len = va_arg(ap, int);
	else
		parse.prec_len = ft_atoi(flags);
	while (*flags == '*' || (*flags >= '0' && *flags <= '9'))
		flags++;
	return (ft_printstr(ap, parse));
}
