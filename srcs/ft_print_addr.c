/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_addr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:14:19 by nieyraud          #+#    #+#             */
/*   Updated: 2019/11/05 16:26:34 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_print_addr(unsigned long int nb)
{
	char *base;
	static int count = 0;

	base = "0123456789abcdef";
	if (nb > 15)
		ft_print_addr(nb / 16);
	ft_putchar_fd(base[nb % 16], 1);
	count++;
	return (count);
}