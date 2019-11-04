/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:03:17 by nieyraud          #+#    #+#             */
/*   Updated: 2019/11/04 05:52:56 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

static	int		ft_print_field(int length, int nb_len, int nbr, t_flags p)
{
	unsigned int	u_nb;

	while (p.minus == 0 && p.pad_value > 0 && length-- > 0)
		write(1, " ", 1);
	if (p.plus == 1 && nbr >= 0)
		write(1, "+", 1);
	else if (p.space == 1 && nbr >= 0)
		write(1, " ", 1);
	else if (nbr < 0)
		write(1, "-", 1);
	while ((p.pad_zero == 1 || p.prec_len > 0) && nb_len-- > 0)
		write(1, "0", 1);
	u_nb = nbr < 0 ? -nbr : nbr;
	if (!(u_nb == 0 && p.prec_len == 0 && p.precision == 1))
		ft_putnbr_fd(u_nb, 1);
	while (p.minus == 1 && length-- > 0)
		write(1, " ", 1);
	if (nbr >= 0 && (p.plus == 1 || p.space == 1))
		return (1);
	return (0);
}

int				ft_printnbr(t_flags p, int nbr)
{
	size_t			length;
	int				count;
	int				field_len;
	int				nb_len;

	if (p.precision == 1 && p.prec_len == 0 && nbr == 0)
		length = 0;
	else
		length = int_length(nbr);
	nb_len = p.prec_len > length ? p.prec_len - length : 0;
	nb_len += (nb_len > 0 && nbr < 0 && p.prec_len > 0) ? 1 : 0;
	if (p.pad_value > length + nb_len)
	{
		field_len = p.pad_value - length - nb_len;
		nbr == 0 && (p.plus == 1 || p.space == 1) ? field_len-- : 0;
	}
	else
		field_len = 0;
	if (p.pad_zero == 1 && p.minus == 0)
		count = ft_print_field(nb_len, field_len, nbr, p);
	else
		count = ft_print_field(field_len, nb_len, nbr, p);
	count += nb_len + field_len + length;
	return (count);
}
