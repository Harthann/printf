/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:09:14 by nieyraud          #+#    #+#             */
/*   Updated: 2019/11/14 14:44:48 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char		*ft_fill_pad(t_flags *p, size_t len)
{
	char	*str;
	size_t	start;
	size_t	count;

	if ((size_t)p->prec_len >= len)
		p->nb_0 = p->prec_len - len;
	if ((size_t)p->pad_value > len + p->nb_0)
		p->spaces = p->pad_value - len - p->nb_0;
	if (!(str = (char*)malloc(sizeof(char) * (p->nb_0 + p->spaces + len + 1))))
		return (NULL);
	str[p->nb_0 + p->spaces + len] = '\0';
	if (!p->pad_zero || p->minus || p->precision)
		ft_memset(str, ' ', p->nb_0 + p->spaces + len);
	else
		ft_memset(str, '0', p->nb_0 + p->spaces + len);
	start = (p->minus == 1 || p->spaces == 0) ? 0 : p->spaces;
	count = p->nb_0;
	while (count-- > 0)
		str[start++] = '0';
	return (str);
}

char			*ft_print_hexa(t_flags p, unsigned int nb, char c)
{
	char	*hexa;
	char	*str;
	size_t	length;

	p.pad_value = p.pad_value < 0 ? 0 : p.pad_value;
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
	str = ft_fill_pad(&p, length);
	if ((nb || p.prec_len || !p.precision) && p.minus == 0)
		ft_memcpy(str + p.spaces + p.nb_0, hexa, length);
	else if (nb || p.prec_len || !p.precision)
		ft_memcpy(str + p.nb_0, hexa, length);
	free(hexa);
	return (str);
}
