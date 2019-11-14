/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 03:56:31 by nieyraud          #+#    #+#             */
/*   Updated: 2019/11/13 10:58:46 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_init_parse(t_flags *p)
{
	p->pad_zero = 0;
	p->pad_value = 0;
	p->precision = 0;
	p->prec_len = 0;
	p->minus = 0;
	p->nb_0 = 0;
	p->spaces = 0;
}
