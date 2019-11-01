/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 09:48:09 by nieyraud          #+#    #+#             */
/*   Updated: 2019/11/01 03:42:37 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int		main(void)
{
	char *str = "avec";
	char *arg = "Je test [%5-d] printf [%02.s] des pointeurs : [%p]\n";

	printf(arg , 0, str, str);
	ft_printf(arg, 0, str, str);
	return (0);
}
