NAME = so_long
CC = gcc
SRC = $(wildcard *.c src/*.c get_next_line/*.c libft/*.c printf/*.c)
OBJ = $(SRC:.c=.o)
RM = rm -rf
CC_FLAGS = -Wall -Wextra -Werror

all : $(NAME)

%.o: %.c
	$(CC)  $(CC_FLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJ)
	@cd MLX42 && cmake -B build && cmake --build build -j4
	@$(CC) $(OBJ) ./MLX42/build/libmlx42.a -Iinclude -lglfw -g -o $(NAME)

clean: 
	@$(RM) $(OBJ)
	@$(RM) ./MLX42/build

fclean:
	@$(RM) $(OBJ)
	@$(RM) $(NAME)
	@$(RM) ./MLX42/build

re: fclean all