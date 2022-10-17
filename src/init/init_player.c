/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:22:34 by jisookim          #+#    #+#             */
/*   Updated: 2022/10/17 11:25:26 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cat3d.h"

void	init_struct_player_direction(t_game *game)
{
	if (game->player.direction == 'N')
	{
		game->param.dir_x = 0;
		game->param.dir_y = -1;
	}
	else if (game->player.direction == 'S')
	{
		game->param.dir_x = 0;
		game->param.dir_y = 1;
	}
	else if (game->player.direction == 'W')
	{
		game->param.dir_x = 1;
		game->param.dir_y = 0;
	}
	else if (game->player.direction == 'E')
	{
		game->param.dir_x = -1;
		game->param.dir_y = 0;
	}
}

void	init_struct_player(t_game *game)
{
	game->param.pos_x = (double)(game->player.pos_x) + 0.5;
	game->param.pos_y = (double)(game->player.pos_y) + 0.5;
	game->player.move_speed = 0.05;
	game->player.rot_speed = 0.05;
	init_struct_player_direction(game);
}
