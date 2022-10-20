/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall_hit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:19:35 by jisookim          #+#    #+#             */
/*   Updated: 2022/10/19 20:03:50 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cat3d.h"

void	init_check_wall_hit(t_game *game)
{
	game->render.wall_offset_x = 0;
	game->render.wall_offset_y = 0;
}

void	move_to_next_map_square(t_game *game, \
									int *side, int *imap_coord, int *door_state)
{
	if (game->render.side_dist_x < game->render.side_dist_y)
	{
		game->render.side_dist_x += game->render.delta_dist_x;
		game->render.map_x += game->render.step_x;
		*side = 0;
	}
	else
	{
		game->render.side_dist_y += game->render.delta_dist_y;
		game->render.map_y += game->render.step_y;
		*side = 1;
	}
	*imap_coord = game->map.imap[game->render.map_y][game->render.map_x];
	*door_state = \
			game->open_door.door_state[game->render.map_y][game->render.map_x];
}

void	side_1_operation(t_game *game, double *wallx, int *hit, int *side)
{
	game->render.wall_offset_y = 0.5 * game->render.step_y;
	game->render.perp_wall_dist = (game->render.map_y - game->param.pos_y + \
				game->render.wall_offset_y + (1 - game->render.step_y) / 2) \
													/ game->render.ray_dir_y;
	*wallx = game->param.pos_x + \
						game->render.perp_wall_dist * game->render.ray_dir_x;
	*wallx -= floor(*wallx);
	if (game->render.side_dist_y - (game->render.delta_dist_y / 2) < \
													game->render.side_dist_x)
	{
		if (1.0 - *wallx <= \
			game->open_door.door_offset[game->render.map_y][game->render.map_x])
		{
			*hit = 0;
			game->render.wall_offset_y = 0;
		}
	}
	else
	{
		game->render.map_x += game->render.step_x;
		*side = 0;
		game->render.wall_offset_y = 0;
	}
}

void	side_0_operation(t_game *game, double *wallx, int *hit, int *side)
{
	game->render.wall_offset_x = 0.5 * game->render.step_x;
	game->render.perp_wall_dist = (game->render.map_x - game->param.pos_x + \
				game->render.wall_offset_x + (1 - game->render.step_x) / 2) \
													/ game->render.ray_dir_x;
	*wallx = game->param.pos_y + \
						game->render.perp_wall_dist * game->render.ray_dir_y;
	*wallx -= floor(*wallx);
	if (game->render.side_dist_x - (game->render.delta_dist_x / 2) < \
													game->render.side_dist_y)
	{
		if (1.0 - *wallx < \
			game->open_door.door_offset[game->render.map_y][game->render.map_x])
		{
			*hit = 0;
			game->render.wall_offset_x = 0;
		}
	}
	else
	{
		game->render.map_y += game->render.step_y;
		*side = 1;
		game->render.wall_offset_x = 0;
	}
}

int	check_wall_hit(t_game *game)
{
	int		side;
	int		hit;
	int		imap_coord;
	int		door_state;
	double	wallx;

	hit = 0;
	wallx = 0;
	init_check_wall_hit(game);
	while (hit == 0)
	{
		move_to_next_map_square(game, &side, &imap_coord, &door_state);
		if ((imap_coord & DOOR) && (door_state != OPEN))
		{
			hit = 1;
			if (side == 1)
				side_1_operation(game, &wallx, &hit, &side);
			else
				side_0_operation(game, &wallx, &hit, &side);
		}
		else if (!((imap_coord & DOOR) && (door_state == OPEN))
			&& (!(imap_coord & SPRITE) && !(imap_coord & EMPTY)))
			hit = 1;
	}
	return (side);
}
