/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 11:48:22 by nieyraud          #+#    #+#             */
/*   Updated: 2019/11/09 17:18:18 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

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

static	char	*ft_print_field(int spaces, int nb_0, int len, t_flags p)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * (spaces + nb_0 + len + 1))))
		return (NULL);
	str[spaces + len + nb_0] = '\0';
	while ((p.pad_zero == 0 || p.precision) && p.minus == 0 && spaces-- > 0)
		str[i++] = ' ';
	while (p.minus == 0 && p.pad_zero == 1 && spaces-- > 0)
		str[i++] = '0';
	while (nb_0-- > 0)
		str[i++] = '0';
	i += len;
	while (spaces-- > 0)
		str[i++] = ' ';
	return (str);
}

int				ft_print_unsigned(t_flags p, unsigned int nbr)
{
	size_t	len;
	size_t	nb_0;
	size_t	nb_space;
	char	*str;

	if (p.precision == 1 && nbr == 0 && p.prec_len == 0 && p.pad_value == 0)
		return (0);
	len = ft_count_length(nbr);
	nb_0 = (size_t)p.prec_len > len ? p.prec_len - len : 0;
	nb_space = (size_t)p.pad_value > len + nb_0 ? p.pad_value - len - nb_0 : 0;
	str = ft_print_field(nb_space, nb_0, len, p);
	while (len > 0)
	{
		if (p.minus == 0)
			str[nb_0 + nb_space + len - 1] = nbr % 10 + '0';
		else
			str[nb_0 + len - 1] = nbr % 10 + '0';
		nbr /= 10;
		len--;
	}
	len = ft_strlen(str);
	write(1, str, len);
	free(str);
	return (len);
}
