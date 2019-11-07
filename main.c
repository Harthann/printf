/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 09:48:09 by nieyraud          #+#    #+#             */
/*   Updated: 2019/11/07 18:40:45 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int		main(void)
{
	int	result1;
	int result2;

	// write(1, "   printf : ", 12);
	result1 = printf("   printf : %Oct\n", 0);
	// write(1, "ft_printf : ", 12);
	result2 = ft_printf("ft_printf : %-025%t\n");
	ft_putnbr_fd(result1, 1);
	write(1, "\t",  1);
	ft_putnbr_fd(result2, 1);
	// write(1, "\n", 1);
	// ft_print_hexa(2147483647);
	return (0);
}
