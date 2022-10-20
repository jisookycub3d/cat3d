/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_mouse_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 11:06:29 by kyhan             #+#    #+#             */
/*   Updated: 2022/10/17 11:55:26 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cat3d.h"

void	rotate_vision(t_game *game, double rot_speed, double old_dir_x, \
															double old_plane_x)
{
	game->param.dir_x = game->param.dir_x * cos(rot_speed) - \
											game->param.dir_y * sin(rot_speed);
	game->param.dir_y = old_dir_x * sin(rot_speed) + \
											game->param.dir_y * cos(rot_speed);
	game->param.plane_x = game->param.plane_x * cos(rot_speed) - \
										game->param.plane_y * sin(rot_speed);
	game->param.plane_y = old_plane_x * sin(rot_speed) + \
										game->param.plane_y * cos(rot_speed);
}

void	mouse_move(t_game *game)
{
	int		x;
	int		y;
	double	rot_speed;

	rot_speed = game->player.rot_speed;
	mlx_mouse_get_pos(game->win, &x, &y);
	if (x - S_WIDTH / 2 > 0)
		rotate_vision(game, rot_speed, game->param.dir_x, game->param.plane_x);
	else if (x - S_WIDTH / 2 < 0)
		rotate_vision(game, -rot_speed, game->param.dir_x, game->param.plane_x);
	mlx_mouse_move(game->win, S_WIDTH / 2, S_HEIGHT / 2);
}
