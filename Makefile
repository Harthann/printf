# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/26 12:54:40 by nieyraud          #+#    #+#              #
#    Updated: 2019/11/07 17:52:06 by nieyraud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_FILE =	ft_printf.c \
			ft_printstr.c \
			ft_parse_string.c \
			ft_parse_digit.c \
			ft_printnbr.c \
			ft_int_length.c \
			ft_init_parse.c \
			ft_parse_char.c \
			ft_parse_ptr.c \
			ft_printptr.c \
			ft_ultoa.c \
			ft_parse_hexa.c \
			ft_print_hexa.c \
			ft_parse_unsigned.c \
			ft_print_unsigned.c \
			ft_parse_percent.c \

LIBFT_SRC = ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memset.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strncmp.c \
			ft_strrchr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_memmove.c \
			ft_strnstr.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_split.c \
			ft_itoa.c \
			ft_strtrim.c \
			ft_strmapi.c \

PATH = srcs/
LIBFT_PATH = libft/

SRCS		= $(addprefix ${PATH}, ${SRC_FILE})
OBJS		= ${SRCS:%.c=%.o}
LIBFT_SRCS  = $(addprefix ${LIBFT_PATH}, ${LIBFT_SRC})
LIBFT_OBJS	= ${LIBFT_SRCS:%.c=%.o}

LIBFT = libftprintf.a
FLAGS = -Wall -Werror -Wextra


all : $(NAME)

$(NAME) : ${OBJS} ${LIBFT_OBJS} ${INCLUDE} 
	@echo Creating ${NAME}
	@ar rc ${NAME} ${OBJS} ${LIBFT_OBJS}

%.o: %.c
	@echo Compiling $<
	@gcc $(FLAGS) -c -I include/  $< -o $@

clean :
	@echo Removing objects files
	@rm -f ${OBJS} ${LIBFT_OBJS}

fclean : clean
	@echo Removing ${NAME}
	@rm -f $(NAME) ${LIBFT}

re : fclean all

.PHONY : all clean fclean re