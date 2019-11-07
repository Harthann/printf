/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 09:44:21 by nieyraud          #+#    #+#             */
/*   Updated: 2019/11/07 17:51:56 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct	s_flags
{
	int		pad_zero;
	size_t	pad_value;
	int		precision;
	size_t	prec_len;
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
int				ft_print_addr(unsigned long int nb);
int				ft_parse_ptr(char *flags, va_list ap);
char			*ft_printptr(t_flags p, unsigned long int ptr);
char			*ft_ultoa(unsigned long int n);
int				ft_parse_hexa(char *flags, va_list ap, char c);
char			*ft_print_hexa(t_flags p, unsigned int nb, char c);
int				ft_parse_unsigned(char *flags, va_list ap);
int				ft_print_unsigned(t_flags p, unsigned int nbr);
int				ft_parse_percent(char *flags, va_list ap);
#endif
