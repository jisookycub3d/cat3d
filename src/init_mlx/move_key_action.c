/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_key_action.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:45:19 by jisookim          #+#    #+#             */
/*   Updated: 2022/10/19 20:16:49 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cat3d.h"

void	press_d(t_game *game)
{
	if (game->open_door.door_state[(int)(game->param.pos_y)] \
						[(int)(game->param.pos_x + game->param.plane_x * \
										game->player.move_speed)] == OPEN
		|| game->map.imap[(int)(game->param.pos_y)][(int)(game->param.pos_x \
					+ game->param.plane_x * game->player.move_speed)] & EMPTY
		|| game->map.imap[(int)(game->param.pos_y)][(int)(game->param.pos_x + \
					game->param.plane_x * game->player.move_speed)] & SPRITE)
		game->param.pos_x += game->param.plane_x * game->player.move_speed;
	if (game->open_door.door_state[(int)(game->param.pos_y + \
						game->param.plane_y * game->player.move_speed)] \
						[(int)(game->param.pos_x)] == OPEN
		|| game->map.imap[(int)(game->param.pos_y + game->param.plane_y * \
					game->player.move_speed)][(int)(game->param.pos_x)] & EMPTY
		|| game->map.imap[(int)(game->param.pos_y + game->param.plane_y * \
				game->player.move_speed)][(int)(game->param.pos_x)] & SPRITE)
		game->param.pos_y += game->param.plane_y * game->player.move_speed;
}

void	press_a(t_game *game)
{
	if (game->open_door.door_state[(int)(game->param.pos_y)] \
						[(int)(game->param.pos_x - game->param.plane_x * \
						game->player.move_speed)] == OPEN
		|| game->map.imap[(int)(game->param.pos_y)] \
						[(int)(game->param.pos_x - game->param.plane_x * \
						game->player.move_speed)] & EMPTY
		|| game->map.imap[(int)(game->param.pos_y)][(int)(game->param.pos_x \
				- game->param.plane_x * game->player.move_speed)] & SPRITE)
		game->param.pos_x -= game->param.plane_x * game->player.move_speed;
	if (game->open_door.door_state[(int)(game->param.pos_y \
						- game->param.plane_y * game->player.move_speed)] \
						[(int)(game->param.pos_x)] == OPEN
		|| game->map.imap[(int)(game->param.pos_y - game->param.plane_y * \
				game->player.move_speed)][(int)(game->param.pos_x)] & EMPTY
		|| game->map.imap[(int)(game->param.pos_y - game->param.plane_y * \
				game->player.move_speed)][(int)(game->param.pos_x)] & SPRITE)
		game->param.pos_y -= game->param.plane_y * game->player.move_speed;
}

void	press_s(t_game *game)
{
	if (game->open_door.door_state[(int)(game->param.pos_y)] \
						[(int)(game->param.pos_x - game->param.dir_x * \
											game->player.move_speed)] == OPEN
		|| game->map.imap[(int)(game->param.pos_y)] \
						[(int)(game->param.pos_x - game->param.dir_x * \
											game->player.move_speed)] & EMPTY
		|| game->map.imap[(int)(game->param.pos_y)][(int)(game->param.pos_x \
				- game->param.dir_x * game->player.move_speed)] & SPRITE)
		game->param.pos_x -= game->param.dir_x * game->player.move_speed;
	if (game->open_door.door_state[(int)(game->param.pos_y \
							- game->param.dir_y * game->player.move_speed)] \
							[(int)(game->param.pos_x)] == OPEN
		|| game->map.imap[(int)(game->param.pos_y - game->param.dir_y * \
				game->player.move_speed)][(int)(game->param.pos_x)] & EMPTY
		|| game->map.imap[(int)(game->param.pos_y - game->param.dir_y * \
				game->player.move_speed)][(int)(game->param.pos_x)] & SPRITE)
		game->param.pos_y -= game->param.dir_y * game->player.move_speed;
}

void	press_w(t_game *game)
{
	if (game->open_door.door_state[(int)(game->param.pos_y)] \
						[(int)(game->param.pos_x + game->param.dir_x * \
									game->player.move_speed)] == OPEN
		|| game->map.imap[(int)(game->param.pos_y)] \
						[(int)(game->param.pos_x + game->param.dir_x * \
									game->player.move_speed)] & EMPTY
		|| game->map.imap[(int)(game->param.pos_y)] \
							[(int)(game->param.pos_x + game->param.dir_x * \
										game->player.move_speed)] & SPRITE)
		game->param.pos_x += game->param.dir_x * game->player.move_speed;
	if (game->open_door.door_state[(int)(game->param.pos_y + \
						game->param.dir_y * game->player.move_speed)] \
						[(int)(game->param.pos_x)] == OPEN
		|| game->map.imap[(int)(game->param.pos_y + game->param.dir_y * \
					game->player.move_speed)][(int)(game->param.pos_x)] & EMPTY
		|| game->map.imap[(int)(game->param.pos_y + game->param.dir_y * \
				game->player.move_speed)][(int)(game->param.pos_x)] & SPRITE)
		game->param.pos_y += game->param.dir_y * game->player.move_speed;
}
