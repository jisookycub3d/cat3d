/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:31:24 by jisookim          #+#    #+#             */
/*   Updated: 2022/10/18 17:57:59 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cat3d.h"

void	set_wall_by_direction(t_game *game, int side)
{
	if (game->map.imap[game->render.map_y][game->render.map_x] & DOOR)
		game->render.tex_num = 4;
	else if (side == 1 && game->render.ray_dir_y < 0)
		game->render.tex_num = 0;
	else if (side == 1 && game->render.ray_dir_y > 0)
		game->render.tex_num = 1;
	else if (side == 0 && game->render.ray_dir_x > 0)
		game->render.tex_num = 2;
	else if (side == 0 && game->render.ray_dir_x < 0)
		game->render.tex_num = 3;
}

double	set_wall_x(t_game *game, int side)
{
	double	wall_x;
	
	if (side == 0)
		wall_x = game->param.pos_y + \
						game->render.perp_wall_dist * game->render.ray_dir_y;
	else
		wall_x = game->param.pos_x + \
						game->render.perp_wall_dist * game->render.ray_dir_x;
	wall_x -= floor(wall_x);
	return (wall_x);
}

void	set_wall_texture(t_game *game, int side)
{
	double	wall_x;

	if (!(game->map.imap[game->render.map_y][game->render.map_x] & EMPTY))
	{
		set_wall_by_direction(game, side);
		if (side == 0 && game->map.imap[game->render.map_y] \
							[game->render.map_x - game->render.step_x] & DOOR)
			game->render.tex_num = 2;
		else if (side == 1 && game->map.imap[game->render.map_y \
							- game->render.step_y][game->render.map_x] & DOOR)
			game->render.tex_num = 2;
	}
	wall_x = set_wall_x(game, side);
	if (game->render.tex_num == 4)
	{
		wall_x += game->open_door.door_offset \
									[game->render.map_y][game->render.map_x];
	}
	game->render.tex_x = (int)(wall_x * (double)TEX_SIZE);
}
