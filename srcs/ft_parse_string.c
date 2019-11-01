/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 20:44:24 by nieyraud          #+#    #+#             */
/*   Updated: 2019/10/31 23:12:15 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_parse_string(char *flags, va_list ap)
{
	t_flags parse;

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
		parse.precision_value = va_arg(ap, int);
	else
		parse.precision_value = ft_atoi(flags);
	while (*flags == '*' || (*flags >= '0' && *flags <= '9'))
		flags++;
	return (ft_printstr(ap, parse));
}
