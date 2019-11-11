/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:03:21 by nieyraud          #+#    #+#             */
/*   Updated: 2019/11/11 15:30:46 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_printptr(t_flags p, unsigned long int ptr)
{
	char	*addr;
	char	*str;
	size_t	length;

	addr = ft_ultoa(ptr);
	str = ft_strjoin("0x", addr);
	free(addr);
	length = ft_strlen(str);
	if (length >= (size_t)p.pad_value)
		return (str);
	if (!(addr = (char*)malloc(sizeof(char) * (p.pad_value + 1))))
		return (NULL);
	addr[p.pad_value] = '\0';
	addr = ft_memset(addr, ' ', p.pad_value);
	if (p.minus == 0)
		ft_memcpy(addr + p.pad_value - length, str, length);
	else
		ft_memcpy(addr, str, length);
	free(str);
	return (addr);
}
