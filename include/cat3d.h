/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:00:14 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/25 22:35:23 by kyhan            ###   ########.fr       */
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

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_texture	texture;
	t_map		map;
	t_rgb		rgb;
	t_player	player;
}				t_game;

/* init.c */
void	init_game(t_game *game);

/* check_arg.c */
void	check_arg(int argc, char **argv);

/* utils.c */
void	exit_with_message(char *msg);
void	ft_free(char **strs);
int		ft_strslen(char **strs);
void	free_game(t_game *game);
int		is_space(char c);

/* parse_map.c */
int	parse_map(t_game *game, char *map);

/* init_texture.c */
int	init_texture(t_game *game, char *gnl, int *checked, int *map_flag);

/* open_texture.c */
void	open_texture(t_game *game, char *path, char *gnl);

/* init_rgb.c */
int	init_rgb(t_game *game, char *gnl, int *checked, int *map_flag);

/* rgb_atoi.c */
int	rgb_atoi(t_game *game, char **rgb, char flag);

/* check_valid.c */
int	check_valid(t_game *game);

/* init_map.c */
int	init_map(t_game *game, char *gnl, int *checked, int *map_flag);

/* check_map.c */
int	check_map(t_game *game);

/* trim_map.c */
void	trim_map_front(t_game *game);
void	trim_map_back(t_game *game);

/* start_game.c */
void	start_game(t_game *game);

#endif
