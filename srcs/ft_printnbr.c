/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:03:17 by nieyraud          #+#    #+#             */
/*   Updated: 2019/11/14 14:50:14 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static	void	ft_print_field(int nbr, t_flags p)
{
	unsigned int	u_nb;

	while (p.minus == 0 && p.spaces-- > 0)
		write(1, " ", 1);
	if (nbr < 0)
		write(1, "-", 1);
	while (p.nb_0-- > 0)
		write(1, "0", 1);
	u_nb = nbr < 0 ? -nbr : nbr;
	if (!(u_nb == 0 && p.prec_len == 0 && p.precision == 1))
		ft_putnbr_fd(u_nb, 1);
	while (p.minus == 1 && p.spaces-- > 0)
		write(1, " ", 1);
}

int				ft_printnbr(t_flags p, int nbr)
{
	size_t	length;

	if (p.precision == 1 && p.prec_len == 0 && nbr == 0)
		length = 0;
	else
		length = int_length(nbr);
	if ((size_t)p.prec_len > length)
		p.nb_0 = p.prec_len - length;
	if ((size_t)p.pad_value > length + p.nb_0)
		p.spaces = p.pad_value - length - p.nb_0;
	if (p.pad_zero && !p.precision && !p.minus)
	{
		p.nb_0 = p.spaces;
		p.spaces = 0;
	}
	if (nbr < 0 && (size_t)p.prec_len > length - 1)
		p.nb_0++;
	if (p.spaces && nbr < 0 && p.nb_0)
		p.spaces--;
	ft_print_field(nbr, p);
	return (p.nb_0 + p.spaces + length);
}
