SRC = src/main.c \
		src/init.c \
		src/map_create.c \
		src/map_validate.c \
		src/draw.c \
		src/render.c \
		src/hook.c \
		src/event.c \
		src/move.c \
		src/utils.c \
		src/free.c
OBJ = main.o \
		init.o \
		map_create.o \
		map_validate.o \
		draw.o \
		render.o \
		hook.o \
		event.o \
		move.o \
		utils.o \
		free.o
NAME = so_long
INC = inc
MLX = mlx/libmlx.a
CFLAGS = -Wextra -Werror -Wall
FRAMEWORKS = -framework OpenGL -framework Appkit

all: $(NAME)

$(NAME): $(OBJ)
	@make -C mlx
	@gcc -o $@ $^ $(FRAMEWORKS) $(MLX)
	@mv *.o obj

$(OBJ): $(SRC)
	@gcc -c $^ -I $(INC)

clean:
	rm -rf obj/*.o

fclean: clean
	rm -rf $(NAME)
	make -C mlx clean

re: fclean
	@make -C ./