/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 09:42:48 by nieyraud          #+#    #+#             */
/*   Updated: 2019/11/05 16:30:30 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int		flags_parse(char *flags, va_list ap, size_t len)
{
	int		count;

	count = 0;
	count += (flags[len - 1] == 's' ? ft_parse_string(flags, ap) : 0);
	count += (flags[len - 1] == 'd' ? ft_parse_digit(flags, ap) : 0);
	count += (flags[len - 1] == 'i' ? ft_parse_digit(flags, ap) : 0);
	count += (flags[len - 1] == 'c' ? ft_parse_char(flags, ap) : 0);
	count += (flags[len - 1] == 'p' ? ft_parse_ptr(flags, ap) : 0);
	return (count);
}

int		ft_printf(const char *str, ...)
{
	va_list ap;
	char	*data_type;
	char	*flags;
	size_t		i;
	int count = 0;

	va_start(ap, str);
	data_type = "cspdiuxX";
	while (*str)
	{
		i = 0;
		if (*str == '%')
		{
			while (ft_strchr(data_type, str[i]) == NULL)
				i++;
			flags = ft_substr(str, 1, i);
			count += flags_parse(flags, ap, i);
		}
		else
		{
			write(1, str, 1);
			count++;
		}
		str += i + 1;
	}
	return (count);
}
