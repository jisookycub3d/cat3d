#include "../../include/cat3d.h"

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
			game->buf[50 + y * 10 + j][50 + x * 10 + i] = rgb;
			j++;
		}
		i++;
	}
}

void	draw_minimap(t_game *game, int type, int x, int y)
{
	if (type & WALL)
		put_minimap_pixel(game, 0x000000, x, y);
	else if (type & EMPTY)
		put_minimap_pixel(game, 0xFFFFFF, x, y);
	else if (type & DOOR)
		put_minimap_pixel(game, 0xFFFF00, x, y);
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
			else if (game->map.imap[y][x] & DOOR)
				draw_minimap(game, DOOR, x, y);
			x++;
		}
		y++;
	}
}