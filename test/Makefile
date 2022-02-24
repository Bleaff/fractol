NAME = fractol
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -ofast
SRC = 	ft_fractol.c ft_utils.c ft_page.c ft_manage_hook.c ft_init_img.c ft_atof_parse.c
HEADERS = fractol.h
MINILIBX = ../minilibx
FTPRINTF = ../FT_PRINTF
OBJ=$(SRC:.c=.o)
GREEN = \033[1;32m

all : $(NAME)

$(NAME) : printf mlx $(OBJ)

		@$(CC) $(CFLAGS) $(SRC) -o $(NAME) -I $(HEADERS) -L ../minilibx -lmlx  -L ../FT_PRINTF -lftprintf -framework OpenGL -framework AppKit

		@echo "$(GREEN)Project successfully compiled"


mlx:
		@make -C ../minilibx
printf:
		@make -C ../FT_PRINTF

.PHONY : clean fclean re

clean :
		-rm -f $(OBJ)
		@echo "$(GREEN)All object files are deleted"

fclean : clean
		@make clean
		-rm -f $(NAME)
		@echo "$(GREEN)Cleaned everything"

re : fclean all
