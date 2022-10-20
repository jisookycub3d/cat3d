/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:06:43 by jisookim          #+#    #+#             */
/*   Updated: 2022/10/20 08:57:31 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cat3d.h"

void	load_image(t_game *game, int *tex, char *path)
{
	int	x;
	int	y;

	x = 0;
	game->image.img = mlx_png_file_to_image(game->mlx, \
									path, &game->image.x, &game->image.y);
	game->image.data = (int *)mlx_get_data_addr(game->image.img, \
				&game->image.bpp, &game->image.size_l, &game->image.endian);
	y = 0;
	while (y < game->image.y)
	{
		x = 0;
		while (x < game->image.x)
		{
			tex[game->image.x * y + x] = \
									game->image.data[game->image.x * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(game->mlx, game->image.img);
}

void	load_texture(t_game *game)
{
	load_image(game, game->tex[0], game->texture.north);
	load_image(game, game->tex[1], game->texture.south);
	load_image(game, game->tex[2], game->texture.east);
	load_image(game, game->tex[3], game->texture.west);
	load_image(game, game->tex[4], "./image/ddoorr.png");
	load_image(game, game->tex[5], "./image/scary.png");
}
