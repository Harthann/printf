/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 01:13:59 by nieyraud          #+#    #+#             */
/*   Updated: 2019/11/02 01:14:19 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	int_length(int nbr)
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
