/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 14:37:37 by nieyraud          #+#    #+#             */
/*   Updated: 2019/11/13 14:47:38 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printstr(va_list ap, t_flags p, size_t i)
{
	size_t		len;
	char		*str;
	char		*to_free;

	str = va_arg(ap, char*);
	if (!str)
	{
		str = ft_strdup("(null)");
		to_free = str;
	}
	else
		to_free = NULL;
	len = ft_strlen(str);
	if (p.precision == 1 && (size_t)p.prec_len < len && (size_t)p.prec_len >= 0)
		len = p.prec_len;
	if (len < (size_t)p.pad_value && p.minus == 0)
		while (i++ < p.pad_value - len)
			p.pad_zero == 1 ? write(1, "0", 1) : write(1, " ", 1);
	write(1, str, len);
	if (len < (size_t)p.pad_value && p.minus == 1)
		while (i++ < (size_t)p.pad_value - len)
			write(1, " ", 1);
	!to_free ? 0 : free(to_free);
	return (len > (size_t)p.pad_value ? len : p.pad_value);
}
