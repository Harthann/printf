NAME = libft.a

SRC_FILE =		ft_atoi.c \
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

BONUS_FILES =	ft_lstadd_back_bonus.c \
				ft_lstadd_front_bonus.c \
				ft_lstclear_bonus.c \
				ft_lstiter_bonus.c \
				ft_lstlast_bonus.c \
				ft_lstdelone_bonus.c \
				ft_lstmap_bonus.c \
				ft_lstnew_bonus.c \
				ft_lstsize_bonus.c


SRCS		= ${SRC_FILE}
OBJS		= $(SRCS:%.c=%.o)
BONUS_SRCS	= ${BONUS_FILES}
BONUS_OBJS	= $(BONUS_SRCS:%.c=%.o)

INCLUDE = libft.h
FLAGS = -Wall -Werror -Wextra


all : $(NAME)

$(NAME) : ${OBJS} ${INCLUDE}
	@echo Creating ${NAME}
	@ar -rcs ${NAME} ${OBJS}

%.o: %.c
	@echo Compiling $<
	@gcc $(FLAGS) -c $< -o $@

bonus : ${NAME} ${BONUS_OBJS}
	@echo Adding bonus to ${NAME}
	@ar -rcs ${NAME} ${BONUS_OBJS}

clean :
	@echo Removing objects files
	@rm -f ${OBJS} ${BONUS_OBJS}

fclean : clean
	@echo Removing ${NAME}
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
