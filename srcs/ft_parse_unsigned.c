/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:56:11 by nieyraud          #+#    #+#             */
/*   Updated: 2019/11/14 13:45:55 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_parse_unsigned(char *flags, va_list ap)
{
	t_flags p;
	char	*str;
	size_t	len;

	ft_init_parse(&p);
	p.pad_zero = *flags == '0';
	while (*flags == '0')
		flags++;
	p.minus = *flags == '-';
	while (*flags == '-')
		flags++;
	p.pad_value = *flags == '*' ? get_number('*', &p, ap, 'u') : ft_atoi(flags);
	while ((*flags >= '0' && *flags <= '9') || *flags == '*')
		flags++;
	p.precision = *flags == '.';
	while (*flags == '.')
		flags++;
	p.prec_len = *flags == '*' ? get_number('.', &p, ap, 's') : ft_atoi(flags);
	str = ft_print_unsigned(p, va_arg(ap, unsigned int));
	len = ft_strlen(str);
	write(1, str, len);
	free(str);
	return (len);
}
