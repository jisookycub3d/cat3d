CC = cc
CFLAGS = -Wall -Werror -Wextra
DFLAGS = -g2 -fsanitize=address

RM = rm -f

SRCS =	src/cat3d.c \
		src/init.c \
		src/check_arg.c \
		src/utils.c \
		src/parsing/parse_map.c \
		src/parsing/check_valid.c \
		src/parsing/init_map.c \
		src/parsing/init_rgb.c \
		src/parsing/init_texture.c \
		src/parsing/open_texture.c \
		src/parsing/rgb_atoi.c \
		src/parsing/check_map.c \
		src/parsing/trim_map.c

SRCS_BONUS = bonus/cat3d_bonus.c

OBJS = $(SRCS:%.c=%.o)
OBJS_BONUS = $(SRCS_BONUS:%.c=%.o)

NAME = cat3D
BONUS = cat3D_bonus

all : $(NAME)

bonus : $(BONUS)

$(NAME) :	$(OBJS)
			@make -C ./mlx
			@clear
			@cat ./decoration/cat
			@make -C ./libft fclean
			@make -C ./libft
			@chmod +x ./decoration/loading.sh
			@./decoration/loading.sh
			@$(CC) $(CFLAGS) $(DFLAGS) $(OBJS) ./libft/libft.a -L./mlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(BONUS) :	$(OBJS_BONUS)
			@make -C ./mlx
			@clear
			@cat ./decoration/cat
			@make -C ./libft fclean
			@make -C ./libft
			@chmod +x ./decoration/loading.sh
			@./decoration/loading.sh
			@$(CC) $(CFLAGS) $(OBJS_BONUS) ./libft/libft.a -L./mlx -lmlx -framework OpenGL -framework AppKit -o $(BONUS)

%.o : %.c
		@$(CC) $(CFLAGS) $(DFLAGS) -Imlx -c $< -o $@

clean :
		@make -C ./mlx clean
		@make -C ./libft fclean
		@$(RM) $(OBJS) $(OBJS_BONUS)

fclean :
		@make -C ./mlx clean
		@make -C ./libft fclean
		@$(RM) $(OBJS) $(NAME) $(OBJS_BONUS) $(BONUS)

re :
	@make fclean
	@make all

.PHONY : all clean fclean re bonus