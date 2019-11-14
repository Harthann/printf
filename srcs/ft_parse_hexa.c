/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 11:51:05 by nieyraud          #+#    #+#             */
/*   Updated: 2019/11/14 14:45:44 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_parse_hexa(char *flags, va_list ap, char c)
{
	t_flags p;
	char	*str;
	int		length;

	ft_init_parse(&p);
	p.pad_zero = *flags == '0';
	while (*flags == '0')
		flags++;
	p.minus = *flags == '-';
	while (*flags == '-')
		flags++;
	p.pad_value = *flags == '*' ? get_number('*', &p, ap, 's') : ft_atoi(flags);
	while ((*flags >= '0' && *flags <= '9') || *flags == '*')
		flags++;
	p.precision = *flags == '.';
	while (*flags == '.')
		flags++;
	p.prec_len = *flags == '*' ? get_number('.', &p, ap, 's') : ft_atoi(flags);
	str = ft_print_hexa(p, va_arg(ap, unsigned int), c);
	length = ft_strlen(str);
	write(1, str, length);
	free(str);
	return (length);
}
