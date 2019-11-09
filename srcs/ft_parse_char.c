/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 02:21:37 by nieyraud          #+#    #+#             */
/*   Updated: 2019/11/09 17:15:41 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_parse_char(char *flags, va_list ap)
{
	t_flags	p;
	char	*str;

	p.minus = *flags == '-';
	while (*flags == '-')
		flags++;
	p.pad_value = *flags == '*' ? ft_get_number('*', &p, ap) : ft_atoi(flags);
	if (p.pad_value <= 1)
	{
		ft_putchar_fd(va_arg(ap, int), 1);
		return (1);
	}
	if (!(str = (char*)malloc(sizeof(char) * (p.pad_value + 1))))
		return (-1);
	str[p.pad_value] = '\0';
	ft_memset(str, ' ', p.pad_value);
	if (p.minus == 1)
		str[0] = va_arg(ap, int);
	else
		str[p.pad_value - 1] = va_arg(ap, int);
	write(1, str, p.pad_value);
	return (p.pad_value);
}
