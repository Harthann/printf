/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 23:25:36 by nieyraud          #+#    #+#             */
/*   Updated: 2019/11/01 03:41:32 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_parse_digit(char *flags, va_list ap)
{
	t_flags parse;
	
	parse.pad_zero = *flags == '0' ? 1 : 0;
	while (*flags == '0')
		flags++;
	parse.pad_space = *flags == ' ' ? 1 : 0;
	while (*flags == ' ')
		flags++;
	parse.plus = *flags == '+' ? 1 : 0;
	while (*flags == '+')
		flags++;
	parse.pad_value = *flags == '*' ? va_arg(ap, int) : ft_atoi(flags);
	while (*flags == '*' || (*flags >= '0' && *flags <= '9'))
		flags++;
	parse.minus = *flags == '-' ? 1 : 0;
	while (*flags == '-')
		flags++;
	parse.precision = *flags == '.' ? 1 : 0;
	return(ft_printnbr(ap, parse));
}
