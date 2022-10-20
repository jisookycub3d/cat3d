/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:03:00 by jisookim          #+#    #+#             */
/*   Updated: 2022/10/19 20:20:48 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cat3d.h"

void	draw(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < S_HEIGHT)
	{
		x = 0;
		while (x < S_WIDTH)
		{
			game->image.data[y * S_WIDTH + x] = game->buf[y][x];
			x++;
		}
		y++;
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
	return ((int)(S_HEIGHT / game->render.perp_wall_dist));
}

void	draw_start_to_end(t_game *game, int line_height)
{
	game->render.draw_start = -line_height / 2 + S_HEIGHT / 2;
	if (game->render.draw_start < 0)
		game->render.draw_start = 0;
	game->render.draw_end = line_height / 2 + S_HEIGHT / 2;
	if (game->render.draw_end >= S_HEIGHT)
		game->render.draw_end = S_HEIGHT - 1;
}

void	render(t_game *game)
{
	int	x;
	int	side;
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
		set_pixel_on_screen(game, line_height, x);
		if (game->sprite_cnt)
			game->sp_param.zbuffer[x] = game->render.perp_wall_dist;
		x++;
	}
	render_sprite(game);
}
