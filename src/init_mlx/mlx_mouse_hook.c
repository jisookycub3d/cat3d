/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_mouse_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 11:06:29 by kyhan             #+#    #+#             */
/*   Updated: 2022/09/30 11:18:10 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cat3d.h"
#include <math.h>

void	mouse_move(t_game *game)
{
	int	x;
	int	y;
	double	rot_speed = 0.03;
	double	old_dir_x;
	double	old_plane_x;

	mlx_mouse_get_pos(game->win, &x, &y);
	if (x - S_WIDTH / 2 > 0)
	{
		old_dir_x = game->param.dir_x;
		game->param.dir_x = game->param.dir_x * cos(rot_speed) - game->param.dir_y * sin(rot_speed);
		game->param.dir_y = old_dir_x * sin(rot_speed) + game->param.dir_y * cos(rot_speed);
		old_plane_x = game->param.plane_x;
		game->param.plane_x = game->param.plane_x * cos(rot_speed) - game->param.plane_y * sin(rot_speed);
		game->param.plane_y = old_plane_x * sin(rot_speed) + game->param.plane_y * cos(rot_speed);
	}
	else if (x - S_WIDTH / 2 < 0)
	{
		old_dir_x = game->param.dir_x;
		game->param.dir_x = game->param.dir_x * cos(-rot_speed) - game->param.dir_y * sin(-rot_speed);
		game->param.dir_y = old_dir_x * sin(-rot_speed) + game->param.dir_y * cos(-rot_speed);
		old_plane_x = game->param.plane_x;
		game->param.plane_x = game->param.plane_x * cos(-rot_speed) - game->param.plane_y * sin(-rot_speed);
		game->param.plane_y = old_plane_x * sin(-rot_speed) + game->param.plane_y * cos(-rot_speed);
	}
	mlx_mouse_move(game->win, S_WIDTH / 2, S_HEIGHT / 2);
}
