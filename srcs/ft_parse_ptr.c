/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:43:15 by nieyraud          #+#    #+#             */
/*   Updated: 2019/11/05 17:59:12 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_parse_ptr(char *flags, va_list ap)
{
	t_flags p;

	(void)flags;
	ft_init_parse(&p);
	while (*flags == '-')
		p.minus = 1;
	p.pad_value = ft_atoi(flags + 1);
	return (ft_printptr(p, va_arg(ap, unsigned long int)));
}