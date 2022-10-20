/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:36:17 by jisookim          #+#    #+#             */
/*   Updated: 2022/10/17 11:23:27 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cat3d.h"

void	init_struct_param_rgb(t_game *game)
{
	game->rgb.floor_rgb = rgb_to_i(game->rgb.floor);
	game->rgb.ceiling_rgb = rgb_to_i(game->rgb.ceiling);
}

void	init_struct_param_plane(t_game *game)
{
	if (game->param.dir_x < 0)
		game->param.plane_y = -0.66;
	else if (game->param.dir_x > 0)
		game->param.plane_y = 0.66;
	else if (game->param.dir_y > 0)
		game->param.plane_x = -0.66;
	else if (game->param.dir_y < 0)
		game->param.plane_x = 0.66;
}

int	rgb_to_i(int *arr)
{
	return (arr[0] * 16 * 16 * 16 * 16 + arr[1] * 16 * 16 + arr[2]);
}

void	init_param(t_game *game)
{
	init_struct_player(game);
	init_struct_param_plane(game);
	init_struct_param_rgb(game);
}
