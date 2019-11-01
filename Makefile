# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/26 12:54:40 by nieyraud          #+#    #+#              #
#    Updated: 2019/10/31 23:54:42 by nieyraud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_FILE =	ft_printf.c \
			ft_printstr.c \
			ft_parse_string.c \
			ft_parse_digit.c \
			ft_printnbr.c \

PATH = srcs/

SRCS		= $(addprefix ${PATH}, ${SRC_FILE})
OBJS		= ${SRCS:%.c=%.o}
LIBFT = libft.a
FLAGS = -Wall -Werror -Wextra


all : $(NAME)

$(NAME) : ${LIBFT} ${OBJS} ${INCLUDE} 
	@echo Creating ${NAME}
	@ar -rcs ${NAME} ${OBJS}

%.o: %.c
	@echo Compiling $<
	@gcc $(FLAGS) -c -I include/ $< -o $@

bonus : ${NAME} ${BONUS_OBJS}
	@echo Adding bonus to ${NAME}
	@ar -rcs ${NAME} ${BONUS_OBJS}

clean :
	@echo Removing objects files
	@rm -f ${OBJS} ${BONUS_OBJS}

fclean : clean
	@echo Removing ${NAME}
	@rm -f $(NAME) ${LIBFT}

re : fclean all

.PHONY : all clean fclean re