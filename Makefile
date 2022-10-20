CC = cc
CFLAGS = -Wall -Werror -Wextra
DFLAGS = -g2 -fsanitize=address

NAME = cub3D

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

SRC_INIT		:=	init_game.c init_map.c init_rgb.c \
					init_texture.c init_sprite.c init_param.c init_player.c
SRC_INIT		:=	$(addprefix $(DIR_INIT)/, $(SRC_INIT))

SRC_INIT_MLX	:=	mlx_key_press.c mlx_mouse_hook.c mlx_key_release.c \
					move_key_action.c
SRC_INIT_MLX	:=	$(addprefix $(DIR_INIT_MLX)/, $(SRC_INIT_MLX))

SRC_MAIN		:=	cat3d.c start_game.c
SRC_MAIN		:=	$(addprefix $(DIR_MAIN)/, $(SRC_MAIN))

SRC_MAP			:=	parse_map.c texture_open.c
SRC_MAP			:=	$(addprefix $(DIR_MAP)/, $(SRC_MAP))

SRC_TOOLS		:=	error.c free_game.c jk_tools.c tool_rgb_atoi.c utils.c
SRC_TOOLS		:=	$(addprefix $(DIR_TOOLS)/, $(SRC_TOOLS))

SRC_RENDER		:=	render.c minimap.c door.c render_sprite.c \
					set_sprite_param.c get_sprite_tex.c render_pixel.c \
					render_texture.c init_render.c check_wall_hit.c \
					load_texture.c time.c
SRC_RENDER		:=	$(addprefix $(DIR_RENDER)/, $(SRC_RENDER))

SRCS			=	$(SRC_CHECK) $(SRC_INIT) $(SRC_INIT_MLX) $(SRC_MAIN) \
					$(SRC_MAP) $(SRC_TOOLS) $(SRC_RENDER)

OBJS = $(SRCS:%.c=%.o)

all : $(NAME)

bonus : $(NAME)

$(NAME) :	$(OBJS)
			@make -C ./mlx clean
			@make -C ./mlx
			@cat ./decoration/cat
			@make -C ./libft fclean
			@make -C ./libft
			@chmod +x ./decoration/loading.sh
			@./decoration/loading.sh
			@$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a -L./mlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
			@install_name_tool -change libmlx.dylib mlx/libmlx.dylib cub3D

$(BONUS) :	$(OBJS)
			@make -C ./mlx clean
			@make -C ./mlx
			@cat ./decoration/cat
			@make -C ./libft fclean
			@make -C ./libft
			@chmod +x ./decoration/loading.sh
			@./decoration/loading.sh
			@$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a -L./mlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
			@install_name_tool -change libmlx.dylib mlx/libmlx.dylib cub3D

%.o : %.c
		@$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean :
		@make -C ./mlx clean
		@make -C ./libft fclean
		@$(RM) $(OBJS)

fclean :
		@make -C ./mlx clean
		@make -C ./libft fclean
		@$(RM) $(OBJS) $(NAME)

re :
	@make fclean
	@make all

.PHONY : all clean fclean re bonus
