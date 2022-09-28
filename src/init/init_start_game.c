/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_start_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:34:42 by kyhan             #+#    #+#             */
/*   Updated: 2022/09/28 14:51:53 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cat3d.h"


int	move_player(t_game *game)
{
	mlx_pixel_put(game->mlx, game->win, \
			game->player.pos_x, game->player.pos_y, rgb_to_i(game->rgb.floor));
	mlx_pixel_put(game->mlx, game->win, \
								game->player.pos_x, game->player.pos_y, 255);
	return (0);
}
