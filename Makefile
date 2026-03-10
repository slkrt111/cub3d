CC = cc

FLAGS = -Wall -Werror -Wextra -lXext -lX11 -lm -lz

WAY = srcs/
WAY2 = srcs/parsing/
WAY3 = srcs/raycasting/

LIB_USE = libft/libft.a

SRCS =  src/main.c \
	src/init_data.c \
	src/parsing/parse_file.c \
	src/parsing/parse_file_utils.c \
	src/parsing/parse_elements.c \
	src/parsing/parse_elements_utils.c \
	src/parsing/parse_map.c \
	src/parsing/parse_map_utils.c \
	src/validation/validate_map.c \
	src/validation/validate_map_utils.c \
	src/utils/memory_utils.c \
	src/utils/get_next_line.c \
	src/raycasting/init_mlx.c \
	src/raycasting/raycasting.c \
	src/raycasting/raycasting_utils.c \
	src/raycasting/render.c \
	src/raycasting/events.c \
	src/raycasting/key_handler.c \
	src/raycasting/player.c \
	src/raycasting/utils_graphics.c \
	src/raycasting/utils_graphics2.c \

OBJS = $(SRCS:.c=.o)
	
NAME = cub3D
	
all: $(NAME)

%.o: %.c
	$(CC) -g -I/usr/include -Imlx_linux -c $< -o $@
	# $(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@
	
$(NAME): $(OBJS)
	@make -C mlx_linux 
	@make -C libft 
	$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux $(FLAGS) $(LIB_USE) -o $(NAME)
	
clean:
	@make clean -C libft 
	@rm -f $(OBJS) 

fclean: clean
	@make fclean -C libft
	@make clean -C mlx_linux
	@rm -f $(NAME)
	
re: fclean all

.PHONY: all fclean clean re