/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_press.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:27:30 by jisookim          #+#    #+#             */
/*   Updated: 2022/10/20 21:21:55 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cat3d.h"

void	key_update(t_game *game)
{
	if (!game->keycode.key_shift)
		game->player.move_speed = 0.05;
	if (game->keycode.key_shift)
		game->player.move_speed = 0.1;
	if (game->keycode.key_d)
		press_d(game);
	if (game->keycode.key_a)
		press_a(game);
	if (game->keycode.key_s)
		press_s(game);
	if (game->keycode.key_w)
		press_w(game);
	if (game->keycode.key_left)
		rotate_vision(game, -game->player.rot_speed, game->param.dir_x, \
														game->param.plane_x);
	if (game->keycode.key_right)
		rotate_vision(game, game->player.rot_speed, game->param.dir_x, \
														game->param.plane_x);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_A)
		game->keycode.key_a = 1;
	if (keycode == KEY_W)
		game->keycode.key_w = 1;
	if (keycode == KEY_D)
		game->keycode.key_d = 1;
	if (keycode == KEY_S)
		game->keycode.key_s = 1;
	if (keycode == KEY_LEFT)
		game->keycode.key_left = 1;
	if (keycode == KEY_RIGHT)
		game->keycode.key_right = 1;
	if (keycode == KEY_SHIFT)
		game->keycode.key_shift = 1;
	return (0);
}

void	press_key_e(t_game *game)
{
	if (game->map.imap[(int)floor(game->param.pos_y)] \
									[(int)floor(game->param.pos_x) + 1] & DOOR)
		game->door = 1;
	if (game->map.imap[(int)floor(game->param.pos_y)] \
									[(int)floor(game->param.pos_x) - 1] & DOOR)
		game->door = 1;
	if (game->map.imap[(int)floor(game->param.pos_y) + 1] \
									[(int)floor(game->param.pos_x)] & DOOR)
		game->door = 1;
	if (game->map.imap[(int)floor(game->param.pos_y) - 1] \
									[(int)floor(game->param.pos_x)] & DOOR)
		game->door = 1;
}

int	press_exit_button(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free_game(game);
	printf("The End\n");
	exit(0);
	return (0);
}
