/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_draw_obj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:49:07 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/28 15:03:57 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cat3d.h"

static void	draw_floor(t_game *game)
{
	int	i;
	int	j;
	int	rgb;

	i = 0;
	rgb = rgb_to_i(game->rgb.floor);
	while (i < 2560)
	{
		j = 0;
		while (j < 1440)
		{
			mlx_pixel_put(game->mlx, game->win, i, j, rgb);
			j++;
		}
		i++;
	}
}

static void	draw_wall(t_game *game, t_image *image)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.map[i])
	{
		j = 0;
		while (game->map.map[i][j])
		{
			if (game->map.map[i][j] & WALL)
			{
				printf ("%d, %d\n", i, j);
				mlx_put_image_to_window(game->mlx, game->win, \
											image->wall_n, j * 64, i * 64);
			}
			j++;
		}
		i++;
	}
}

static void	draw_player(t_game *game)
{
	mlx_pixel_put(game->mlx, game->win, \
								game->player.pos_x, game->player.pos_y, 255);
}

void	init_draw_obj(t_game *game, t_image *image)
{
	draw_floor(game);
	draw_wall(game, image);
	draw_player(game);
}
