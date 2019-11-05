/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 14:37:37 by nieyraud          #+#    #+#             */
/*   Updated: 2019/11/05 13:02:48 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <string.h>
#include <stdio.h>

int		ft_printstr(va_list ap, t_flags parsed)
{
	size_t		len;
	size_t		i;
	char	*str;
	char	*to_free;

	str = va_arg(ap, char*);
	if (!str)
	{
		str = ft_strdup("(null)");
		to_free = str;
	}
	else
		to_free = NULL;
	len = ft_strlen(str);
	if (parsed.precision == 1 && parsed.prec_len < len)
		len = parsed.prec_len;
	i = 0;
	if (len < parsed.pad_value && parsed.minus == 0)
		while (i++ < parsed.pad_value - len)
			parsed.pad_zero == 1 ? write(1, "0", 1) : write(1, " ", 1);
	write(1, str, len);
	if (len < parsed.pad_value && parsed.minus == 1)
		while (i++ < parsed.pad_value - len)
			write(1, " ", 1);
	!to_free ? 0 : free(to_free);
	return (len > parsed.pad_value ? len : parsed.pad_value);
}
