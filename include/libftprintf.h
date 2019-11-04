/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 09:44:21 by nieyraud          #+#    #+#             */
/*   Updated: 2019/11/04 05:18:48 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"
# include <unistd.h>
# include <stdarg.h>

typedef struct	s_flags
{
	int		pad_zero;
	size_t		pad_value;
	int		precision;
	size_t		prec_len;
	int		minus;
	int		plus;
	int		space;
	char	type;
}				t_flags;

int				ft_printf(const char *str, ...);
int				ft_printstr(va_list ap, t_flags parsed);
int				ft_parse_string(char *flags, va_list ap);
int				ft_parse_digit(char *flags, va_list ap);
int				ft_printnbr(t_flags parse, int nbr);
int				int_length(int nbr);
void			ft_init_parse(t_flags *p);
int				ft_parse_char(char *flags, va_list ap);

#endif
