CC = cc
CFLAGS = -Wall -Werror -Wextra
DFLAGS = -g2 -fsanitize=address

RM = rm -f

SRCS = src/cat3d.c
SRCS_BONUS = src/cat3d_bonus.c

OBJS = $(SRCS:%.c=%.o)
OBJS_BONUS = $(SRCS_BONUS:%.c=%.o)

NAME = cat3D
BONUS = cat3D_bonus

all : $(NAME)

bonus : $(BONUS)

$(NAME) :	$(OBJS)
			@make -C ./libft fclean
			@make -C ./libft
			@./loading.sh
			@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) ./libft/libft.a

$(BONUS) :	$(OBJS_BONUS)
			@make -C ./libft fclean
			@make -C ./libft
			@./loading.sh
			@$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(BONUS) ./libft/libft.a

%.o : %.c
		@$(CC) -c $< -o $@

clean :
		@make -C ./libft fclean
		@$(RM) $(OBJS) $(OBJS_BONUS)

fclean :
		@make -C ./libft fclean
		@$(RM) $(OBJS) $(NAME) $(OBJS_BONUS) $(BONUS)

re :
	@make fclean
	@make all

run :
	@cat ascii_art/cat
	@make re
	@make clean
	@exec ./cat3d

.PHONY : all clean fclean re run bonus