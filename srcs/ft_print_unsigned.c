/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 11:48:22 by nieyraud          #+#    #+#             */
/*   Updated: 2019/11/15 17:00:14 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static	int		ft_count_length(unsigned long int n)
{
	int		length;

	length = 1;
	while (n / 10 > 0)
	{
		length++;
		n = n / 10;
	}
	return (length);
}

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

char			*ft_print_unsigned(t_flags p, unsigned int nb)
{
	char	*str;
	size_t	length;

	p.pad_value = p.pad_value < 0 ? 0 : p.pad_value;
	if (p.precision == 1 && nb == 0 && p.prec_len == 0 && p.pad_value == 0)
		return (NULL);
	length = ft_count_length(nb);
	str = ft_fill_pad(&p, length);
	while (length > 0)
	{
		if ((nb || p.prec_len || !p.precision) && p.minus == 0)
			str[p.nb_0 + p.spaces + length - 1] = nb % 10 + '0';
		else if ((nb || p.prec_len || !p.precision))
			str[p.nb_0 + length - 1] = nb % 10 + '0';
		nb /= 10;
		length--;
	}
	return (str);
}
