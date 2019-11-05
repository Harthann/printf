/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:03:21 by nieyraud          #+#    #+#             */
/*   Updated: 2019/11/05 17:55:21 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int		ft_printptr(t_flags p, unsigned long int ptr)
{
	char	*addr;
	char	*str;
	size_t	length;

	addr = ft_ultoa(ptr);
	str = ft_strjoin("0x", addr + 1);
	free(addr);
	length = ft_strlen(str);
	if (length >= p.pad_value)
	{
		write(1, str, length);
		free(str);
		return (length);
	}
	if (!(addr = (char*)malloc(sizeof(char) * (p.pad_value + 1))))
		return (-1);
	addr[p.pad_value] = '\0';
	addr = ft_memset(addr, ' ', p.pad_value);
	p.minus == 1 ? ft_memcpy(addr + length, str, length) : ft_memcpy(addr, str, length);
	write(1, addr, ft_strlen(addr));
	free(addr);
	free(str);
	return (p.pad_value > length ? p.pad_value : length);
}