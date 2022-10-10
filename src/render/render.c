#include "../../include/cat3d.h"
#include <math.h>

void	draw(t_game *game)
{
	for (int y = 0; y < S_HEIGHT; y++)
	{
		for (int x = 0; x < S_WIDTH; x++)
		{
			game->image.data[y * S_WIDTH + x] = game->buf[y][x];
		}
	}
	mlx_put_image_to_window(game->mlx, game->win, game->image.img, 0, 0);
}

void	init_render(t_game *game, int x)
{
	game->render.camera_x = -(2 * x / (double)S_WIDTH - 1);
	game->render.ray_dir_x = game->param.dir_x + game->param.plane_x * game->render.camera_x;
	game->render.ray_dir_y = game->param.dir_y + game->param.plane_y * game->render.camera_x;
	
	game->render.map_x = (int)game->param.pos_x;
	game->render.map_y = (int)game->param.pos_y;

	//length of ray from current position to next x or y-side
	
		//length of ray from one x or y-side to next x or y-side
	game->render.delta_dist_x = fabs(1 / game->render.ray_dir_x);
	game->render.delta_dist_y = fabs(1 / game->render.ray_dir_y);
		//what direction to step in x or y-direction (either +1 or -1)
}

void	init_ray_direction(t_game *game)
{
	if (game->render.ray_dir_x < 0)
	{
		game->render.step_x = -1;
		game->render.side_dist_x = (game->param.pos_x - game->render.map_x) * game->render.delta_dist_x;
	}
	else
	{
		game->render.step_x = 1;
		game->render.side_dist_x = (game->render.map_x + 1.0 - game->param.pos_x) * game->render.delta_dist_x;
	}
	if (game->render.ray_dir_y < 0)
	{
		game->render.step_y = -1;
		game->render.side_dist_y = (game->param.pos_y - game->render.map_y) * game->render.delta_dist_y;
	}
	else
	{
		game->render.step_y = 1;
		game->render.side_dist_y = (game->render.map_y + 1.0 - game->param.pos_y) * game->render.delta_dist_y;
	}
}

int	check_wall_hit(t_game *game)
{
	int side;
	int hit;

	hit = 0; //was there a wall hit?
	while (hit == 0)
	{
		//jump to next map square, OR in x-direction, OR in y-direction
		if (game->render.side_dist_x < game->render.side_dist_y)
		{
			game->render.side_dist_x += game->render.delta_dist_x;
			game->render.map_x += game->render.step_x;
			side = 0;
		}
		else
		{
			game->render.side_dist_y += game->render.delta_dist_y;
			game->render.map_y += game->render.step_y;
			side = 1;
		}
		//Check if ray has hit a wall
		if (!(game->map.imap[game->render.map_y][game->render.map_x] & EMPTY)) hit = 1;
	}
	return (side);
}

int	set_line_height(t_game *game, int side)
{
	if (side == 0)
		game->render.perp_wall_dist = (game->render.map_x - game->param.pos_x + (1 - game->render.step_x) / 2) / game->render.ray_dir_x;
	else
		game->render.perp_wall_dist = (game->render.map_y - game->param.pos_y + (1 - game->render.step_y) / 2) / game->render.ray_dir_y;
	//Calculate height of line to draw on screen
	return((int)(S_HEIGHT / game->render.perp_wall_dist));
}

void	draw_start_to_end(t_game *game, int line_height)
{
		//calculate lowest and highest pixel to fill in current stripe
		game->render.draw_start = - line_height / 2 + S_HEIGHT / 2;
		if(game->render.draw_start < 0)
			game->render.draw_start = 0;
		game->render.draw_end = line_height / 2 + S_HEIGHT / 2;
		if(game->render.draw_end >= S_HEIGHT)
			game->render.draw_end = S_HEIGHT - 1;
}

void		set_wall_texture(t_game *game, int side)
{
	double	wall_x;

	if (!(game->map.imap[game->render.map_y][game->render.map_x] & EMPTY))
		game->render.tex_num = 0;
	if (side == 0)
		wall_x = game->param.pos_y + game->render.perp_wall_dist * game->render.ray_dir_y;
	else
		wall_x = game->param.pos_x + game->render.perp_wall_dist * game->render.ray_dir_x;
	wall_x -= floor(wall_x);
	game->render.tex_x = (int)(wall_x * (double)TEX_SIZE);
	if (side == 0 && game->render.ray_dir_x > 0)
		game->render.tex_x = TEX_SIZE - game->render.tex_x - 1;
	if (side == 1 && game->render.ray_dir_y < 0)
		game->render.tex_x = TEX_SIZE - game->render.tex_x - 1;
}

void	set_pixel_on_screen(t_game *game, int line_height, int side, int x)
{
	double step;
	double	tex_pos;
	int		y;
	
	step = 1.0 * TEX_SIZE / line_height;
	tex_pos = (game->render.draw_start - S_HEIGHT / 2 + line_height / 2) * step;
	y = game->render.draw_start;
	while (y < game->render.draw_end)
	{
		int	tex_y = (int)tex_pos & (TEX_SIZE - 1);
		tex_pos += step;
		int	color = game->tex[game->render.tex_num][TEX_SIZE * tex_y + game->render.tex_x];
		if (side == 1)
			color = (color >> 1) & 8355711;
		game->buf[y][x] = color;
		y++;
	}
	y = -1;
	while (++y < game->render.draw_start)
		game->buf[y][x] = game->rgb.ceiling_rgb;
	y = game->render.draw_end - 1;
	while (++y < S_HEIGHT)
		game->buf[y][x] = game->rgb.floor_rgb;
}

void	render(t_game *game)
{
	int	x;
	int	side;	//was a NS or a EW wall hit?
	int	line_height;

	x = 0;
	while (x < S_WIDTH)
	{
		init_render(game, x);
		init_ray_direction(game);
		side = check_wall_hit(game);
		line_height = set_line_height(game, side);
		draw_start_to_end(game, line_height);
		set_wall_texture(game, side);
		set_pixel_on_screen(game, line_height, side, x);
		x++;
	}
}

void	load_image(t_game *game, int *tex, char *path)
{
	game->image.img = mlx_png_file_to_image(game->mlx, path, &game->image.x, &game->image.y);
	game->image.data = (int *)mlx_get_data_addr(game->image.img, &game->image.bpp, &game->image.size_l, &game->image.endian);
	for (int y = 0; y < game->image.y; y++)
	{
		for (int x = 0; x < game->image.x; x++)
		{
			tex[game->image.x * y + x] = game->image.data[game->image.x * y + x];
		}
	}
	mlx_destroy_image(game->mlx, game->image.img);
}

void	load_texture(t_game *game)
{
	load_image(game, game->tex[0], "./jisoocat2.png");
	load_image(game, game->tex[1], "./jisoocat.png");
	load_image(game, game->tex[2], "./jisoocat.png");
	load_image(game, game->tex[3], "./jisoocat.png");
	load_image(game, game->tex[4], "./jisoocat.png");
	load_image(game, game->tex[5], "./jisoocat.png");
}

int	main_loop(t_game *game)
{
    mouse_move(game);
	render(game);
    minimap(game);
	draw(game);
	return (0);
}
