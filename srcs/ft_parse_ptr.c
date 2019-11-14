/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:43:15 by nieyraud          #+#    #+#             */
/*   Updated: 2019/11/13 15:21:36 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_parse_ptr(char *flags, va_list ap)
{
	t_flags p;
	char	*str;
	int		length;

	ft_init_parse(&p);
	while (*flags == '-')
	{
		p.minus = 1;
		flags++;
	}
	p.pad_value = *flags == '*' ? get_number('*', &p, ap, 'p') : ft_atoi(flags);
	str = ft_printptr(p, va_arg(ap, unsigned long int));
	length = ft_strlen(str);
	if (str)
	{
		write(1, str, length);
		free(str);
	}
	return (length);
}
