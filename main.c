/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 09:48:09 by nieyraud          #+#    #+#             */
/*   Updated: 2019/11/04 06:45:59 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int		main(void)
{
	// char *str = NULL;
	char *arg = "%.3s\n";
	int		result1;
	int result2;

	write(1, "   printf : ", 12);
	result1 = printf(arg , NULL);
	write(1, "ft_printf : ", 12);
	result2 = ft_printf(arg, NULL);
	write(1, "\n",  1);
	ft_putnbr_fd(result1, 1);
	write(1, "\t",  1);
	ft_putnbr_fd(result2, 1);
	return (0);
}
