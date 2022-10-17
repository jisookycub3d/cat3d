/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:30:33 by jisookim          #+#    #+#             */
/*   Updated: 2022/10/17 11:48:18 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cat3d.h"

int	translucent_color(int origin, int map)
{
	int	color[3];

	color[0] = 3 * (origin / 65536) / 4 + (map / 65536) / 4;
	color[1] = (3 * (origin / (256)) % (256)) / 4 + ((map / 256) % 256) / 4;
	color[2] = 3 * (origin % 256) / 4 + (map % 256) / 4;
	return (color[0] * 65536 + color[1] * 256 + color[2]);
}

void	put_minimap_pixel(t_game *game, int rgb, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			game->buf[y * 10 + j][x * 10 + i] = \
					translucent_color(game->buf[y * 10 + j][x * 10 + i], rgb);
			j++;
		}
		i++;
	}
}

void	draw_player(t_game *game)
{
	double	ipart;
	int		buf_x;
	int		buf_y;

	buf_x = (int)floor(game->param.pos_y) * 10 + \
						(int)floor(modf(game->param.pos_y, &ipart) * 10);
	buf_y = (int)floor(game->param.pos_x) * 10 + \
						(int)floor(modf(game->param.pos_x, &ipart) * 10);
	game->buf[buf_x][buf_y] = 0xACFF0000;
	game->buf[buf_x + 1][buf_y] = 0xACFF0000;
	game->buf[buf_x - 1][buf_y] = 0xACFF0000;
	game->buf[buf_x][buf_y + 1] = 0xACFF0000;
	game->buf[buf_x][buf_y - 1] = 0xACFF0000;
	game->buf[buf_x + 1][buf_y - 1] = 0xACFF0000;
	game->buf[buf_x - 1][buf_y + 1] = 0xACFF0000;
	game->buf[buf_x + 1][buf_y + 1] = 0xACFF0000;
	game->buf[buf_x - 1][buf_y - 1] = 0xACFF0000;
	(void)ipart;
}

void	draw_minimap(t_game *game, int type, int x, int y)
{
	if (type & WALL)
		put_minimap_pixel(game, 0x000000, x, y);
	else if (type & EMPTY)
		put_minimap_pixel(game, 0xFFFFFF, x, y);
	else if (type & DOOR)
		put_minimap_pixel(game, 0xFFFF00, x, y);
	else if (type & SPRITE)
		put_minimap_pixel(game, 0x0000FF, x, y);
	draw_player(game);
}

void	minimap(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y <= game->map.height)
	{
		x = 0;
		while (x <= game->map.width)
		{
			if (game->map.imap[y][x] & WALL)
				draw_minimap(game, WALL, x, y);
			else if (game->map.imap[y][x] & EMPTY)
				draw_minimap(game, EMPTY, x, y);
			else if (game->map.imap[y][x] & SPRITE)
				draw_minimap(game, SPRITE, x, y);
			else if (game->map.imap[y][x] & DOOR)
				draw_minimap(game, DOOR, x, y);
			x++;
		}
		y++;
	}
}
