/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:03:17 by nieyraud          #+#    #+#             */
/*   Updated: 2019/11/02 03:45:24 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

static	void	ft_print_field(int length,int nb_len, int nbr, t_flags p)
{
	unsigned int	u_nb;

	while (p.minus == 0 && p.pad_value > 0 && length > 0)
	{
		write(1, " ", 1);
		length--;
	}
	if (p.pad_zero == 1 || p.prec_len > 0)
	{
		if (p.plus == 1 && nbr > 0 )
			write(1, "+", 1);
		else if (p.space == 1 && nbr > 0)
			write(1, " ", 1);
		else if(nbr < 0)
			write(1, "-", 1);
	}
	while ((p.pad_zero == 1 || p.prec_len > 0) && nb_len > 0)
	{
		write(1, "0", 1);
		nb_len--;
	}
	if (p.pad_zero == 1 && nbr < 0)
		u_nb = -nbr;
	else
		u_nb = nbr;
	ft_putnbr_fd(u_nb, 1);
	while (p.minus == 1 && length > 0)
	{
		write(1, " ", 1);
		length--;
	}
}

int		ft_printnbr(va_list ap, t_flags p)
{
	int				nbr;
	int				length;
	int				field_len;
	int				nb_len;

	nbr = va_arg(ap, int);
	length = int_length(nbr);
	p.pad_zero = p.precision == 1 ? 0 : p.pad_zero;
	if (p.precision == 1 && nbr == 0)
		return (0);
	if (p.plus == 1 && nbr > 0)
		p.pad_value--;
	nb_len = p.prec_len > length ? p.prec_len - length : 0;
	if (p.pad_value > length + nb_len)
		field_len = p.pad_value - length - nb_len;
	else
		field_len = 0;
	ft_print_field(field_len, nb_len, nbr, p);
	return (0);
}