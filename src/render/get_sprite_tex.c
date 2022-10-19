/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprite_tex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:48:14 by jisookim          #+#    #+#             */
/*   Updated: 2022/10/19 20:03:07 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cat3d.h"

void	sp_param_draw_sprite_texture(t_game *game, int i, int tex_x, int stripe)
{
	int	tex_y;
	int	y;
	int	color;
	int	d;

	y = game->sp_param.draw_start_y;
	while (y < game->sp_param.draw_end_y)
	{
		d = (y - game->sp_param.vmove_screen) * 256 - \
				S_HEIGHT * 128 + game->sp_param.sprite_height * 128;
		tex_y = ((d * TEX_SIZE) / game->sp_param.sprite_height) / 256;
		if (tex_x < 0)
			tex_x = abs(tex_x);
		if (tex_y < 0)
			tex_y = abs(tex_y);
		color = game->tex[game->sprite[game->sprite_order[i]].texture] \
							[TEX_SIZE * tex_y + tex_x];
		if ((color & 0x00FFFFFF) != 0)
			game->buf[y][stripe] = color;
		y++;
	}
}

void	get_sprite_tex(t_game *game, int i)
{
	int	stripe;
	int	tex_x;

	stripe = game->sp_param.draw_start_x;
	while (stripe < game->sp_param.draw_end_x)
	{
		tex_x = (int)((256 * (stripe - (-game->sp_param.sprite_width / 2 + \
						game->sp_param.sprite_screen_x)) * TEX_SIZE / \
											game->sp_param.sprite_width) / 256);
		if ((game->sp_param.transform_y > 0) && (stripe > 0)
			&& (stripe < S_WIDTH)
			&& (game->sp_param.transform_y < game->sp_param.zbuffer[stripe]))
			sp_param_draw_sprite_texture(game, i, tex_x, stripe);
		stripe++;
	}
}
