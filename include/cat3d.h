/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:00:14 by jisookim          #+#    #+#             */
/*   Updated: 2022/10/03 12:50:07 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT3D_H
# define CAT3D_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"

#define X_EVENT_PRESS_KEY 2
#define X_EVENT_KEY_RELEASE 3
#define X_EVENT_EXIT_BUTTON 17

# define KEY_W 13       
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53 
# define KEY_LEFT 123
# define KEY_RIGHT 124

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum e_words
{
	WALL = 1 << 0,
	EMPTY = 1 << 1,
	DIRECTION = 1 << 2,
	DOOR = 1 << 3,
	SPACE = 1 << 4
};

typedef struct s_texture
{
	char		*north;
	char		*south;
	char		*east;
	char		*west;
}				t_texture;

typedef struct s_map
{
	char	**map;
	int		**imap;
}				t_map;

typedef struct s_rgb
{
	int			*floor;
	int			*ceiling;
}				t_rgb;

typedef struct s_player
{
	char		direction;
	int			pos_x;
	int			pos_y;
}				t_player;

typedef struct s_param
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
}				t_param;

typedef struct s_image
{
	void	*wall_n;
	void	*wall_s;
	void	*wall_w;
	void	*wall_e;
	void	*door;
}				t_image;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_texture	texture;
	t_map		map;
	t_rgb		rgb;
	t_player	player;
	t_param		param;
	t_image		image;
}				t_game;

/* check_arg.c */
void	check_arg(int argc, char **argv);

/* check_content.c */
int	check_content(t_game *game);

/* check_map_trim.c */
void	trim_map_front(t_game *game);
void	trim_map_back(t_game *game);

/* check_map.c */
int	check_map(t_game *game);
int	get_direct_pos(t_game *game, char c, int i, int j);
int	check_wall(t_game *game, int i, int j);

/* check_valid.c */
int	check_valid(t_game *game);

/* init_game.c */
void	init_game(t_game *game);
int		init_content(t_game *game, char *gnl);

/* init_map.c */
int	init_map(t_game *game, char *gnl, int *checked, int *map_flag);

/* init_rgb.c */
int	init_rgb(t_game *game, char *gnl, int *checked, int *map_flag);

/* init_texture.c */
int	init_texture(t_game *game, char *gnl, int *checked, int *map_flag);

/* init_start_game.c */
int	move_player(t_game *game);

/* parse_map.c */
int	parse_map(t_game *game, char *mapfile);

/* init_draw_obj.c */
void	init_draw_obj(t_game *game, t_image *image);

/* mlx_init_img.c */
void	init_image(t_game *game, t_image *image);

/* mlx_key_press.c */
int	key_press(int keycode, t_game *game);
int	press_exit_button(t_game *game);

/* start_game.c */
void	start_game(t_game *game);

/* texture_open.c */
void	open_texture(t_game *game, char *path, char *gnl);

/* error.c */
void	exit_with_message(char *msg);

/* free_game.c */
void	free_game(t_game *game);

/* jk_tools.c */
int	is_space(char c);
int	ft_strslen(char **strs);
void	ft_free(char **strs);
int	ft_strlen_without_space(char *str);

/* tool_rgb_atoi.c */
int	rgb_atoi(t_game *game, char **rgb, char flag);

/* utils.c */
char	bit_mask(char c);
int		rgb_to_i(int *arr);


int	main_loop(t_game *game);

#endif
