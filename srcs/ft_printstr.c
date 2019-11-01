/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 14:37:37 by nieyraud          #+#    #+#             */
/*   Updated: 2019/10/31 23:22:37 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <string.h>

int		ft_printstr(va_list ap, t_flags parsed)
{
	int		len;
	int		i;
	char	*str;

	str = va_arg(ap, char*);
	len = ft_strlen(str);
	if (len > parsed.precision_value)
		len = parsed.precision_value;
	i = 0;
	if (len < parsed.pad_value && parsed.minus == 0)
		while (i < parsed.pad_value - len)
		{
			parsed.pad_zero == 1 ? write(1, "0", 1) : write(1, " ", 1);
			i++;
		}
	write(1, str, len);
	if (len < parsed.pad_value && parsed.minus == 1)
		while (i < parsed.pad_value - len)
		{
				write(1, " ", 1);
			i++;
		}
	return (len + parsed.pad_value);
}
