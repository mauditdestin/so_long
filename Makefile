NAME = so_long

CFLAGS = -Wall -Wextra -Werror -Iinclude -g
MLXFLAGS = ./MLX42/build/libmlx42.a -I./MLX42/include -ldl -lglfw -pthread -lm
LDFLAGS = -Llib -lftprintf
CC = cc

SRC = $(wildcard *.c) $(wildcard checking/*.c) $(wildcard srcs/*.c)
OBJ = $(SRC:.c=.o)

all:
	@if ! test -d MLX42; then \
		git clone https://github.com/codam-coding-college/MLX42.git; \
	fi
	cd MLX42 && cmake -B build && cmake --build build -j4
	make $(NAME)

%.o:		%.c
			$(CC)  $(CFLAGS) -I./MLX42/include -c $< -o $@

$(NAME):	$(OBJ)
			cd lib; make
			$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(MLXFLAGS) $(LDFLAGS)

clean:
			cd lib; make clean
			$(RM) -f $(OBJ)
			$(RM) -rf MLX42/build

fclean:		clean
			cd lib; make fclean
			$(RM) -f $(NAME)
			$(RM) -rf MLX42

re:			fclean all

test:
			@make re
			@make clean
			@clear
			@echo "\033[1;92mDONE !"

norminette:
			@clear
#			@sh ~/better_norminette.sh
			@norminette -R CheckDefine include
			@norminette -R CheckForbiddenSourceHeader main.c
			@norminette -R CheckForbiddenSourceHeader checking
			@norminette -R CheckForbiddenSourceHeader game
			@norminette -R CheckForbiddenSourceHeader lib

.PHONY: all clean fclean re