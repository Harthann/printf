/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:09:14 by nieyraud          #+#    #+#             */
/*   Updated: 2019/11/09 17:17:47 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

static char		*ft_fill_pad(t_flags *p, size_t len)
{
	char	*str;
	size_t	start;
	size_t	nb_0;
	size_t	spaces;

	nb_0 = (size_t)p->prec_len > len ? p->prec_len - len : 0;
	spaces = (size_t)p->pad_value > len + nb_0 ? p->pad_value - len - nb_0 : 0;
	p->pad_value = spaces;
	p->prec_len = nb_0;
	if (!(str = (char*)malloc(sizeof(char) * (nb_0 + spaces + len))))
		return (NULL);
	str[nb_0 + spaces + len] = '\0';
	if (p->pad_zero == 0 || p->minus == 1 || p->precision == 1)
		ft_memset(str, ' ', nb_0 + spaces + len);
	else
		ft_memset(str, '0', nb_0 + spaces + len);
	if (p->minus == 1 || spaces == 0)
		start = 0;
	else
		start = spaces;
	while (nb_0-- > 0)
		str[start++] = '0';
	return (str);
}

char			*ft_print_hexa(t_flags p, unsigned int nb, char c)
{
	char	*hexa;
	char	*str;
	size_t	length;

	if (p.precision == 1 && nb == 0 && p.prec_len == 0 && p.pad_value == 0)
		return (NULL);
	hexa = ft_ultoa(nb);
	length = ft_strlen(hexa);
	str = hexa;
	while (*hexa && c == 'X')
	{
		*hexa -= *hexa >= 'a' && *hexa <= 'z' ? 32 : 0;
		hexa++;
	}
	hexa = str;
	if (length >= (size_t)p.pad_value && length >= (size_t)p.prec_len)
		return (hexa);
	str = ft_fill_pad(&p, length);
	if (!(nb == 0 && p.prec_len == 0) && p.minus == 0)
		ft_memcpy(str + p.pad_value + p.prec_len, hexa, length);
	else if (!(nb == 0 && p.prec_len == 0))
		ft_memcpy(str + p.prec_len, hexa, length);
	free(hexa);
	return (str);
}
