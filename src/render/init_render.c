/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:26:38 by jisookim          #+#    #+#             */
/*   Updated: 2022/10/19 20:09:59 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cat3d.h"

void	init_render(t_game *game, int x)
{
	game->render.camera_x = (2 * x / (double)S_WIDTH - 1);
	game->render.ray_dir_x = game->param.dir_x + \
									game->param.plane_x * game->render.camera_x;
	game->render.ray_dir_y = game->param.dir_y + \
									game->param.plane_y * game->render.camera_x;
	game->render.map_x = (int)game->param.pos_x;
	game->render.map_y = (int)game->param.pos_y;
	game->render.delta_dist_x = fabs(1 / game->render.ray_dir_x);
	game->render.delta_dist_y = fabs(1 / game->render.ray_dir_y);
}

void	init_ray_dir_x(t_game *game)
{
	if (game->render.ray_dir_x < 0)
	{
		game->render.step_x = -1;
		game->render.side_dist_x = (game->param.pos_x - \
								game->render.map_x) * game->render.delta_dist_x;
	}
	else
	{
		game->render.step_x = 1;
		game->render.side_dist_x = (game->render.map_x + \
						1.0 - game->param.pos_x) * game->render.delta_dist_x;
	}
}

void	init_ray_dir_y(t_game *game)
{
	if (game->render.ray_dir_y < 0)
	{
		game->render.step_y = -1;
		game->render.side_dist_y = (game->param.pos_y - \
							game->render.map_y) * game->render.delta_dist_y;
	}
	else
	{
		game->render.step_y = 1;
		game->render.side_dist_y = (game->render.map_y + 1.0 - \
								game->param.pos_y) * game->render.delta_dist_y;
	}
}

void	init_ray_direction(t_game *game)
{
	init_ray_dir_x(game);
	init_ray_dir_y(game);
}
