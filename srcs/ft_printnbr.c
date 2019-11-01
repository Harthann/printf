/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:03:17 by nieyraud          #+#    #+#             */
/*   Updated: 2019/11/01 05:51:42 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	int_length(int nbr)
{
	int				count;
	unsigned int	nb;

	nb = nbr < 0 ? -nbr : nbr;
	count = 0;
	if (nbr == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 10;
		count++;
	}
	return (nbr < 0 ? count + 1 : count);
}

int		ft_printnbr(va_list ap, t_flags parse)
{
	int				nbr;
	unsigned int	u_nb;
	int				length;
	int				zero_nb;

	nbr = va_arg(ap, int);
	length = int_length(nbr);
	parse.pad_zero = parse.precision == 1 ? 0 : parse.pad_zero;
	if (parse.precision == 1 && nbr == 0)
		return (0);
	if (parse.pad_zero == 1)
	{
		if (parse.plus == 1 && nbr > 0 )
			write(1, "+", 1);
		else if (nbr < 0)
			write(1, "-", 1);
	}
	if (parse.plus == 1 && nbr > 0)
		parse.pad_value--;
	zero_nb = parse.pad_value > length ? parse.pad_value - length : length - parse.pad_value;
	if (parse.pad_zero == 1 && nbr < 0)
		u_nb = -nbr;
	parse.minus == 0 ? write(1, )
	ft_putnbr_fd(nbr < 0 ? u_nb : nbr, 1);
	return (0);
}