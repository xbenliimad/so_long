NAME= so_long

SRC= ./src/main.c \
./src/parsing.c \
./src/utils.c \
./src/handle_checker.c \
./src/custom.c \
./src/handle_flood_fill.c \
./src/handle_game.c \
./src/handle_images.c \
./src/handle_movements.c \

SRC_BONUS = ./bonus/custom_bonus.c \
./bonus/handle_flood_fill_bonus.c \
./bonus/handle_images_bonus.c \
./bonus/main_bonus.c \
./bonus/handle_checker_bonus.c \
./bonus/handle_game_bonus.c \
./bonus/handle_movements_bonus.c \
./bonus/parsing_bonus.c \
./bonus/utils_bonus.c \

OBJ=$(SRC:%.c=%.o)

OBJ_BONUS=$(SRC_BONUS:%.c=%.o)

INCLUDES= -I./includes -I./utils/libft -I./utils/get-next-line -I./utils/ft_printf

FLAGS= -Wall -Wextra -Werror $(INCLUDES)

CC= cc

%.o:%.c
	$(CC) $(FLAGS) -c -Imlx $^ -o $@

all : $(NAME) 

$(NAME) : $(OBJ) ./utils/libft/libft.a ./utils/ft_printf/libftprintf.a ./utils/get-next-line/get_next_line.a
	$(CC) $(FLAGS) $^ -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@
	# $(CC) $(FLAGS) $^ -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $@

bonus : $(OBJ_BONUS) ./utils/libft/libft.a ./utils/ft_printf/libftprintf.a ./utils/get-next-line/get_next_line.a
	$(CC) $(FLAGS) $^ -Lmlx -lmlx -framework OpenGL -framework AppKit -o so_long
	# $(CC) $(FLAGS) $^ -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o so_long

./utils/libft/libft.a :
	make -C ./utils/libft  bonus


./utils/ft_printf/libftprintf.a :
	make -C ./utils/ft_printf

./utils/get-next-line/get_next_line.a :
	make -C ./utils/get-next-line


clean :
	rm -f $(OBJ)
	rm -f $(OBJ_BONUS)
	make -C ./utils/libft clean
	make -C ./utils/ft_printf clean
	make -C ./utils/get-next-line clean

fclean : clean
	rm -f $(NAME)
	make -C ./utils/libft fclean
	make -C ./utils/ft_printf fclean
	make -C ./utils/get-next-line fclean

re : fclean all


.PHONY : all fclean clean re