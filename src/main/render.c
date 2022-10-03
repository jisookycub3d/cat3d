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
	for(int x = 0; x < 1080; x++)
	{
		double	camera_x = 2 * x / 1080.0 - 1;
		double	ray_dir_x = game->param.dir_x + game->param.plane_x * camera_x;
		double	ray_dir_y = game->param.dir_y + game->param.plane_y * camera_x;

		int		map_x = (int)(game->param.pos_x);
		int		map_y = (int)(game->param.pos_y);
		double	side_dist_x;
		double	side_dist_y;
		double	delta_dist_x = fabs(1 / ray_dir_x);
		double	delta_dist_y = fabs(1 / ray_dir_y);
		double	perp_wall_dist;

		int	step_x;
		int	step_y;
		int	hit = 0;
		int	side;

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
			if (game->map.imap[map_x][map_y] & WALL)
				hit = 1;
		}
		if (side == 0)
			perp_wall_dist = (map_x - game->param.pos_x + (1 - step_x) / 2) / ray_dir_x;
		else
			perp_wall_dist = (map_y - game->param.pos_y + (1 - step_y) / 2) / ray_dir_y;
		
		int	line_height = (int)(720 / perp_wall_dist);
		int	draw_start = -line_height / 2 + 720 / 2;
		if (draw_start < 0)
			draw_start = 0;
		int	draw_end = line_height / 2 + 720 / 2;
		if (draw_end >= 720)
			draw_end = 720 - 1;
		int	color;
		if (game->map.imap[map_x][map_y])
			color = 255;
		if (side == 1)
			color = color / 2;
		verLine(game, x, draw_start, draw_end, color);
	}
}

int	main_loop(t_game *game)
{
	render(game);
	return (0);
}
