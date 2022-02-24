# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bleaf <bleaf@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/12 01:28:49 by bleaf             #+#    #+#              #
#    Updated: 2022/01/12 01:30:10 by bleaf            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 	= 	ft_printf.c\
		ft_printf_utils.c\
		ft_printf_utils_2.c\
		ft_printf_utils_3.c\

OBJS	= ${SRCS:.c=.o}

HEADER	= ft_printf.h

NAME	= libftprintf.a

CC	= gcc

LIBCC	= ar rcs

CFLAGS	= -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: $(NAME)

${OBJS}: ${HEADER} Makefile

${NAME}: $(OBJS) 
	${LIBCC} ${NAME} $?

clean:
	@rm -rf ${OBJS}

fclean:	clean
	@rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re