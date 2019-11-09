/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 16:26:42 by nieyraud          #+#    #+#             */
/*   Updated: 2019/11/09 17:23:07 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_get_number(char c, t_flags *p, va_list ap)
{
	int nb;

	nb = va_arg(ap, int);
	if (nb < 0 && c != '.')
	{
		p->minus = 1;
		return (-nb);
	}
	else if (nb < 0 && c == '.')
		return (0);
	else
		return (nb);
}
