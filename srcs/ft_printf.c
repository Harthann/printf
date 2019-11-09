/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 09:42:48 by nieyraud          #+#    #+#             */
/*   Updated: 2019/11/09 17:58:04 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		flags_parse(char *flags, va_list ap, size_t len)
{
	int		count;

	count = 0;
	if (flags[len - 1] == 's')
		count += ft_parse_string(flags, ap);
	else if (flags[len - 1] == 'd' || flags[len - 1] == 'i')
		count += ft_parse_digit(flags, ap);
	else if (flags[len - 1] == 'c')
		count += ft_parse_char(flags, ap);
	else if (flags[len - 1] == '%')
		count += ft_parse_percent(flags, ap);
	else if (flags[len - 1] == 'p')
		count += ft_parse_ptr(flags, ap);
	else if (flags[len - 1] == 'x' || flags[len - 1] == 'X')
		count += ft_parse_hexa(flags, ap, flags[len - 1]);
	else if (flags[len - 1] == 'u')
		count += ft_parse_unsigned(flags, ap);
	return (count);
}

static void		ft_browse_string(char *str, va_list ap, int *count)
{
	int		i;
	char	*flags;
	char	*data_type;

	data_type = "%cspdiuxX";
	while (*str)
	{
		i = 1;
		if (*str == '%')
		{
			while (ft_strchr(data_type, str[i]) == NULL)
				i++;
			flags = ft_substr(str, 1, i);
			count += flags_parse(flags, ap, i++);
			free(flags);
		}
		else
		{
			write(1, str, 1);
			count++;
		}
		str += i;
	}
}

int				ft_printf(const char *str, ...)
{
	va_list ap;
	int		count;

	va_start(ap, str);
	ft_browse_string(str, ap, &count);
	va_end(ap);
	return (count);
}
