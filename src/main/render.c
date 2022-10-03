#include "../../include/cat3d.h"
#include <math.h>

void	verLine(t_game *game, int x, int y1, int y2, int color)
{
	int	y;

	y = y1;
	while (y <= y2)
	{
		mlx_pixel_put(game->mlx, game->win, x, y, color);
		y++;
	}
}

void	render(t_game *game)
{
	int	x;

	x = 0;
	while (x < 640)
	{
		double cameraX = 2 * x / (double)640 - 1;
		double rayDirX = game->param.dir_x + game->param.plane_x * cameraX;
		double rayDirY = game->param.dir_y + game->param.plane_y * cameraX;
		
		int mapX = (int)game->param.pos_x;
		int mapY = (int)game->param.pos_y;

		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;
		
		 //length of ray from one x or y-side to next x or y-side
		double deltaDistX = fabs(1 / rayDirX);
		double deltaDistY = fabs(1 / rayDirY);
		double perpWallDist;
		
		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;
		
		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?

		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (game->param.pos_x - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - game->param.pos_x) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (game->param.pos_y - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - game->param.pos_y) * deltaDistY;
		}

		while (hit == 0)
		{
			//jump to next map square, OR in x-direction, OR in y-direction
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			if (!(game->map.imap[mapY][mapX] & EMPTY)) hit = 1;
		}
		if (side == 0)
			perpWallDist = (mapX - game->param.pos_x + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - game->param.pos_y + (1 - stepY) / 2) / rayDirY;

		//Calculate height of line to draw on screen
		int lineHeight = (int)(480 / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + 480 / 2;
		if(drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + 480 / 2;
		if(drawEnd >= 480)
			drawEnd = 480 - 1;

		int	color;
		if (game->map.imap[mapY][mapX] & WALL)
			color = 0xFF0000;
		else if (game->map.imap[mapY][mapX] & DOOR)
			color = 0x00FF00;
		else if (game->map.imap[mapY][mapX] & EMPTY)
			color = 0xFFFF00;
		else if (game->map.imap[mapY][mapX] & DIRECTION)
			color = 0xFFFF00;
		
		if (side == 1)
			color = color / 2;

		verLine(game, x, drawStart, drawEnd, color);
		
		x++;
	}
}

int	main_loop(t_game *game)
{
	render(game);
	return (0);
}
