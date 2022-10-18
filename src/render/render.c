/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:03:00 by jisookim          #+#    #+#             */
/*   Updated: 2022/10/18 17:43:38 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cat3d.h"

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

int	set_line_height(t_game *game, int side)
{
	if (side == 0)
		game->render.perp_wall_dist = (game->render.map_x - game->param.pos_x \
				+ game->render.wall_offset_x + (1 - game->render.step_x) / 2) \
													/ game->render.ray_dir_x;
	else
		game->render.perp_wall_dist = (game->render.map_y - game->param.pos_y \
				+ game->render.wall_offset_y + (1 - game->render.step_y) / 2) \
													/ game->render.ray_dir_y;
	return((int)(S_HEIGHT / game->render.perp_wall_dist));
}

void	draw_start_to_end(t_game *game, int line_height)
{
		game->render.draw_start = - line_height / 2 + S_HEIGHT / 2;
		if(game->render.draw_start < 0)
			game->render.draw_start = 0;
		game->render.draw_end = line_height / 2 + S_HEIGHT / 2;
		if(game->render.draw_end >= S_HEIGHT)
			game->render.draw_end = S_HEIGHT - 1;
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
	load_image(game, game->tex[0], game->texture.north);
	load_image(game, game->tex[1], game->texture.south);
	load_image(game, game->tex[2], game->texture.east);
	load_image(game, game->tex[3], game->texture.west);
	load_image(game, game->tex[4], "./door.png");
	load_image(game, game->tex[5], "./ghost.png");
}

void	render(t_game *game)
{
	int	x;
	int	side;	//was a NS or a EW wall hit?
	int	line_height;

	x = 0;
	while (x < S_WIDTH)
	{
		init_render(game, x);			//init/init_render.c
		init_ray_direction(game);		//init/init_render.c
		side = check_wall_hit(game);	//check/check_wall_hit.c
		line_height = set_line_height(game, side);
		draw_start_to_end(game, line_height);
		set_wall_texture(game, side);	//render/render_texture.c
		set_pixel_on_screen(game, line_height, x);
		if (game->sprite_cnt)
			game->sp_param.zbuffer[x] = game->render.perp_wall_dist;
		x++;
	}
	render_sprite(game);
}
