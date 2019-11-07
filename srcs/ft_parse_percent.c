/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:21:43 by nieyraud          #+#    #+#             */
/*   Updated: 2019/11/07 18:27:40 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_fill(t_flags p)
{
	char *str;
	if (!(str = (char*)malloc(sizeof(char) * (p.pad_value + 1))))
		return (NULL);
	str[p.pad_value] = '\0';
	if (p.pad_zero && !p.minus)
		ft_memset(str, '0', p.pad_value);
	else
		ft_memset(str, ' ', p.pad_value);
	if (p.minus == 1)
		str[0] = '%';
	else
		str[p.pad_value - 1] = '%';
	return (str);
}

int			ft_parse_percent(char *flags, va_list ap)
{
	t_flags	p;
	char	*str;

	p.pad_zero = *flags == '0';
	while (*flags == '0' || *flags == '+')
		flags++;
	p.minus = *flags == '-';
	while (*flags == '-' || *flags == '+')
		flags++;
	p.pad_value = *flags == '*' ? va_arg(ap, int) : ft_atoi(flags);
	if (p.pad_value <= 1)
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	str = ft_fill(p);
	write(1, str, p.pad_value);
	return (p.pad_value);
}