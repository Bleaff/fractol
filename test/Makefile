NAME = fractol
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
SRC = 	ft_fractol.c ft_complex.c ft_support_page.c
HEADERS = fractol.h
MINILIBX = minilibx/liblmx.a
OBJ=$(SRC:.c=.o)
GREEN = \033[1;32m

all : $(NAME)

$(NAME) :$(OBJ)
		$(CC) $(CFLAGS) $(SRC) -o $(NAME) -I $(HEADERS) -L ../minilibx -lmlx -framework OpenGL -framework AppKit

		@echo "$(GREEN)Project successfully compiled"


$(MINILIBX):
		make minilibx

.PHONY : clean fclean re

clean :
		-rm -f $(OBJ)
		@echo "$(GREEN)All object files are deleted"

fclean : clean
		@make clean
		-rm -f $(NAME)
		@echo "$(GREEN)Cleaned everything"

re : fclean all
