#include "../../include/cat3d.h"
#include <math.h>

void	ver_line(t_game *game, int x, int y1, int y2, int color)
{
	int	y;

	y = y1;
	while (y <= y2)
	{
		mlx_pixel_put(game->mlx, game->win, x, y, color);
		y++;
	}
}
void	draw(t_game *game)
{
	for (int y = 0; y < 480; y++)
	{
		for (int x = 0; x < 640; x++)
		{
			game->image.data[y * 640 + x] = game->map.buf[y][x];
		}
	}
	mlx_put_image_to_window(game->mlx, game->win, game->image.wall_w, 0, 0);
}

void	render(t_game *game)
{
	int	x;

	x = 0;
	if (game->re_buf == 1)
	{
		for (int i = 0; i < 480; i++)
		{
			for (int j = 0; j < 640; j++)
			{
				game->map.buf[i][j] = 0;
			}
		}
		game->re_buf = 0;
	}
	while (x < 640)
	{
		double camera_x = 2 * x / (double)640 - 1;
		double ray_dir_x = game->param.dir_x + game->param.plane_x * camera_x;
		double ray_dir_y = game->param.dir_y + game->param.plane_y * camera_x;
		
		int map_x = (int)game->param.pos_x;
		int map_y = (int)game->param.pos_y;

		//length of ray from current position to next x or y-side
		double side_dist_x;
		double side_dist_y;
		
		 //length of ray from one x or y-side to next x or y-side
		double delta_dist_x = fabs(1 / ray_dir_x);
		double delta_dist_y = fabs(1 / ray_dir_y);
		double perp_wall_dist;
		
		//what direction to step in x or y-direction (either +1 or -1)
		int step_x;
		int step_y;
		
		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?

		if (ray_dir_x < 0)
		{
			step_x = -1;
			side_dist_x = (game->param.pos_x - map_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1.0 - game->param.pos_x) * delta_dist_x;
		}
		if (ray_dir_y < 0)
		{
			step_y = -1;
			side_dist_y = (game->param.pos_y - map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1.0 - game->param.pos_y) * delta_dist_y;
		}

		while (hit == 0)
		{
			//jump to next map square, OR in x-direction, OR in y-direction
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1;
			}
			//Check if ray has hit a wall
			if (!(game->map.imap[map_y][map_x] & EMPTY)) hit = 1;
		}
		if (side == 0)
			perp_wall_dist = (map_x - game->param.pos_x + (1 - step_x) / 2) / ray_dir_x;
		else
			perp_wall_dist = (map_y - game->param.pos_y + (1 - step_y) / 2) / ray_dir_y;

		//Calculate height of line to draw on screen
		int line_height = (int)(480 / perp_wall_dist);

		//calculate lowest and highest pixel to fill in current stripe
		int draw_start = -line_height / 2 + 480 / 2;
		if(draw_start < 0)
			draw_start = 0;
		int draw_end = line_height / 2 + 480 / 2;
		if(draw_end >= 480)
			draw_end = 480 - 1;
		int tex_num;
		if (!(game->map.imap[map_y][map_x] & EMPTY))
			tex_num = 0;

		double	wall_x;
		if (side == 0)
			wall_x = game->param.pos_y + perp_wall_dist * ray_dir_y;
		else
			wall_x = game->param.pos_x + perp_wall_dist * ray_dir_x;
		wall_x -= floor(wall_x);
		int	tex_x = (int)(wall_x * (double)64);
		if (side == 0 && ray_dir_x > 0)
			tex_x = 64 - tex_x - 1;
		if (side == 1 && ray_dir_y < 0)
			tex_x = 64 - tex_x - 1;
		double step = 1.0 * 64 / line_height;
		double	tex_pos = (draw_start - 480 / 2 + line_height / 2) * step;
		for (int y = draw_start; y < draw_end; y++)
		{
			int	tex_y = (int)tex_pos & (64 - 1);
			tex_pos += step;
			int	color = game->map.tex[tex_num][64 * tex_y + tex_x];
			if (side == 1)
				color = (color >> 1) & 8355711;
			game->map.buf[y][x] = color;
			game->re_buf = 1;
		}
		// int	color;
		// if (game->map.imap[map_y][map_x] & WALL)
		// 	color = 0xFF0000;
		// else if (game->map.imap[map_y][map_x] & DOOR)
		// 	color = 0x00FF00;
		// else if (game->map.imap[map_y][map_x] & EMPTY)
		// 	color = 0xFFFF00;
		// else if (game->map.imap[map_y][map_x] & DIRECTION)
		// 	color = 0xFFFF00;
		
		// if (side == 1)
		// 	color = color / 2;

		// ver_line(game, x, draw_start, draw_end, color);
		
		x++;
	}
}

int	main_loop(t_game *game)
{
	render(game);
	draw(game);
	return (0);
}
