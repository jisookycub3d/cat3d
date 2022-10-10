CC = cc
CFLAGS = -Wall -Werror -Wextra
DFLAGS = -g2 -fsanitize=address

NAME = cat3D
BONUS = cat3D_bonus

RM = rm -f

SRCS_DIR := ./src

DIR_CHECK		:=	$(SRCS_DIR)/check
DIR_INIT		:=	$(SRCS_DIR)/init
DIR_INIT_MLX	:=	$(SRCS_DIR)/init_mlx
DIR_MAIN		:=	$(SRCS_DIR)/main
DIR_MAP			:=	$(SRCS_DIR)/map
DIR_TOOLS		:=	$(SRCS_DIR)/tools
DIR_RENDER		:=	$(SRCS_DIR)/render

SRC_CHECK		:=	check_arg.c check_content.c	check_map_trim.c check_map.c \
					check_valid.c
SRC_CHECK		:=	$(addprefix $(DIR_CHECK)/, $(SRC_CHECK))

SRC_INIT		:=	init_game.c init_map.c init_rgb.c init_start_game.c \
					init_texture.c
SRC_INIT		:=	$(addprefix $(DIR_INIT)/, $(SRC_INIT))

SRC_INIT_MLX	:=	mlx_key_press.c mlx_mouse_hook.c
SRC_INIT_MLX	:=	$(addprefix $(DIR_INIT_MLX)/, $(SRC_INIT_MLX))

SRC_MAIN		:=	cat3d.c start_game.c
SRC_MAIN		:=	$(addprefix $(DIR_MAIN)/, $(SRC_MAIN))

SRC_MAP			:=	parse_map.c texture_open.c
SRC_MAP			:=	$(addprefix $(DIR_MAP)/, $(SRC_MAP))

SRC_TOOLS		:=	error.c free_game.c jk_tools.c tool_rgb_atoi.c utils.c
SRC_TOOLS		:=	$(addprefix $(DIR_TOOLS)/, $(SRC_TOOLS))

SRC_RENDER		:=	render.c minimap.c door.c
SRC_RENDER		:=	$(addprefix $(DIR_RENDER)/, $(SRC_RENDER))

SRCS			=	$(SRC_CHECK) $(SRC_INIT) $(SRC_INIT_MLX) $(SRC_MAIN) \
					$(SRC_MAP) $(SRC_TOOLS) $(SRC_RENDER)

SRCS_BONUS = bonus/cat3d_bonus.c

OBJS = $(SRCS:%.c=%.o)
OBJS_BONUS = $(SRCS_BONUS:%.c=%.o)

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
			@install_name_tool -change libmlx.dylib mlx/libmlx.dylib cat3D

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
