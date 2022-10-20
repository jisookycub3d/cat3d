/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:44:08 by jisookim          #+#    #+#             */
/*   Updated: 2022/10/19 20:04:40 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cat3d.h"

void	render_draw_start_to_end(t_game *game, \
										int x, double step, int line_height)
{
	int		y;
	int		tex_y;
	double	tex_pos;
	int		color;

	tex_pos = (game->render.draw_start - S_HEIGHT / 2 + line_height / 2) * step;
	y = game->render.draw_start;
	while (y < game->render.draw_end)
	{
		tex_y = (int)tex_pos & (TEX_SIZE - 1);
		tex_pos += step;
		color = game->tex[game->render.tex_num][TEX_SIZE * \
													tex_y + game->render.tex_x];
		game->buf[y][x] = color;
		y++;
	}
}

void	set_pixel_on_screen(t_game *game, int line_height, int x)
{
	int		y;
	double	step;

	step = 1.0 * TEX_SIZE / line_height;
	render_draw_start_to_end(game, x, step, line_height);
	y = -1;
	while (++y < game->render.draw_start)
		game->buf[y][x] = game->rgb.ceiling_rgb;
	y = game->render.draw_end - 1;
	while (++y < S_HEIGHT)
		game->buf[y][x] = game->rgb.floor_rgb;
}
