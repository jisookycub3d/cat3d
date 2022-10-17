/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sprite_param.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:38:50 by jisookim          #+#    #+#             */
/*   Updated: 2022/10/17 12:00:03 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cat3d.h"

void	sp_param_sprite_coord(t_game *game, int i)
{
	game->sp_param.sprite_x = \
					game->sprite[game->sprite_order[i]].x - game->param.pos_x;
	game->sp_param.sprite_y = \
				game->sprite[game->sprite_order[i]].y - game->param.pos_y;
}

void	sp_param_transform_coord(t_game *game, int int_det)
{
	game->sp_param.transform_x = int_det * (game->param.dir_y * \
		game->sp_param.sprite_x - game->param.dir_x * game->sp_param.sprite_y);
	game->sp_param.transform_y = int_det * \
				(-game->param.plane_y * game->sp_param.sprite_x + \
								game->param.plane_x * game->sp_param.sprite_y);
}

void	sp_param_draw_y(t_game *game)
{
	game->sp_param.draw_start_y = -game->sp_param.sprite_height / 2 + \
									S_HEIGHT / 2 + game->sp_param.vmove_screen;
	if (game->sp_param.draw_start_y < 0)
		game->sp_param.draw_start_y = 0;
	game->sp_param.draw_end_y = game->sp_param.sprite_height / 2 + \
									S_HEIGHT / 2 + game->sp_param.vmove_screen;
	if (game->sp_param.draw_end_y >= S_HEIGHT)
		game->sp_param.draw_end_y = S_HEIGHT - 1;
}

void	sp_param_draw_x(t_game *game)
{
	game->sp_param.draw_start_x = -game->sp_param.sprite_width / 2 + \
												game->sp_param.sprite_screen_x;
	if (game->sp_param.draw_start_x < 0)
		game->sp_param.draw_start_x = 0;
	game->sp_param.draw_end_x = game->sp_param.sprite_width / 2 + \
												game->sp_param.sprite_screen_x;
	if (game->sp_param.draw_end_x >= S_WIDTH)
		game->sp_param.draw_end_x = S_WIDTH - 1;
}

void	set_sprite_param(t_game *game, int i)
{
	double	int_det;

	sp_param_sprite_coord(game, i);
	int_det = 1.0 / (game->param.plane_x * game->param.dir_y - \
									game->param.dir_x * game->param.plane_y);
	sp_param_transform_coord(game, int_det);
	game->sp_param.sprite_screen_x = (int)(S_WIDTH / 2) *\
				(1 + game->sp_param.transform_x / game->sp_param.transform_y);
	game->sp_param.vmove_screen = (int)(VMOVE / game->sp_param.transform_y);
	game->sp_param.sprite_height = \
					(int)fabs((S_HEIGHT / game->sp_param.transform_y) / VDIV);
	sp_param_draw_y(game);
	game->sp_param.sprite_width = \
					(int)fabs((S_HEIGHT / game->sp_param.transform_y) / UDIV);
	sp_param_draw_x(game);
}
