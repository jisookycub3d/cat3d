/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:00:14 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/21 15:47:14 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT3D_H
# define CAT3D_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
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
	char	**map
	char	direction;
}				t_map;

typedef struct s_rgb
{
	int			*floor;
	int			*ceiling;
}				t_rgb;


typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_texture	texture;
	t_map		map;
}				t_game;



/* init.c */
void	init_game(t_game *game);

/* check_arg.c */
void	check_arg(int argc, char **argv);

/* utils.c */
void	exit_with_message(char *msg);

/* parse_map.c */
int	parse_map(t_game *game, char *map);

#endif