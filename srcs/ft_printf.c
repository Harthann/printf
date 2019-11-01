/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 09:42:48 by nieyraud          #+#    #+#             */
/*   Updated: 2019/10/31 23:42:05 by nieyraud         ###   ########.fr       */
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
	return (count);
}

int		ft_printf(const char *str, ...)
{
	va_list ap;
	char	*data_type;
	char	*flags;
	size_t		i;
	size_t		j;

	va_start(ap, str);
	data_type = "cspdiuxX";
	while (*str)
	{
		j = 0;
		i = 0;
		while (str[j] != '%' && str[j] != '\0')
			j++;
		write(1, str, j);
		str += j;
		if (*str == '%')
		{
			while (ft_strchr(data_type, str[i]) == NULL)
				i++;
			flags = ft_substr(str, 1, i);
			flags_parse(flags, ap, i);
		}
		str += i + 1;
	}
	return (0);
}
