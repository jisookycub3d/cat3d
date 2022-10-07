/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_press.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:09:22 by jisookim          #+#    #+#             */
/*   Updated: 2022/10/05 17:55:11 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cat3d.h"
#include <math.h>

int	key_press(int keycode, t_game *game)
{
	double	move_speed = 0.1;
	double	rot_speed = 0.1;
	
	if (keycode == KEY_ESC)
		press_exit_button(game);
	if (keycode == KEY_A)
	{
		if (game->map.imap[(int)(game->param.pos_y)][(int)(game->param.pos_x - game->param.plane_x * move_speed)] & EMPTY)
			game->param.pos_x -= game->param.plane_x * move_speed;
		if (game->map.imap[(int)(game->param.pos_y - game->param.plane_y * move_speed)][(int)(game->param.pos_x)] & EMPTY)
			game->param.pos_y -= game->param.plane_y * move_speed;
	}
	if (keycode == KEY_D)
	{
		if (game->map.imap[(int)(game->param.pos_y)][(int)(game->param.pos_x + game->param.plane_x * move_speed)] & EMPTY)
			game->param.pos_x += game->param.plane_x * move_speed;
		if (game->map.imap[(int)(game->param.pos_y + game->param.plane_y * move_speed)][(int)(game->param.pos_x)] & EMPTY)
			game->param.pos_y += game->param.plane_y * move_speed;
	}
	if (keycode == KEY_S)
	{
		if (game->map.imap[(int)(game->param.pos_y)][(int)(game->param.pos_x - game->param.dir_x * move_speed)] & EMPTY)
			game->param.pos_x -= game->param.dir_x * move_speed;
		if (game->map.imap[(int)(game->param.pos_y - game->param.dir_y * move_speed)][(int)(game->param.pos_x)] & EMPTY)
			game->param.pos_y -= game->param.dir_y * move_speed;
	}
	if (keycode == KEY_W)
	{
		if (game->map.imap[(int)(game->param.pos_y)][(int)(game->param.pos_x + game->param.dir_x * move_speed)] & EMPTY)
			game->param.pos_x += game->param.dir_x * move_speed;
		if (game->map.imap[(int)(game->param.pos_y + game->param.dir_y * move_speed)][(int)(game->param.pos_x)] & EMPTY)
			game->param.pos_y += game->param.dir_y * move_speed;
	}
	if (keycode == KEY_LEFT)
	{
		double	old_dir_x = game->param.dir_x;
		game->param.dir_x = game->param.dir_x * cos(-rot_speed) - game->param.dir_y * sin(-rot_speed);
		game->param.dir_y = old_dir_x * sin(-rot_speed) + game->param.dir_y * cos(-rot_speed);
		double	old_plane_x = game->param.plane_x;
		game->param.plane_x = game->param.plane_x * cos(-rot_speed) - game->param.plane_y * sin(-rot_speed);
		game->param.plane_y = old_plane_x * sin(-rot_speed) + game->param.plane_y * cos(-rot_speed);
	}
	if (keycode == KEY_RIGHT)
	{
		double	old_dir_x = game->param.dir_x;
		game->param.dir_x = game->param.dir_x * cos(rot_speed) - game->param.dir_y * sin(rot_speed);
		game->param.dir_y = old_dir_x * sin(rot_speed) + game->param.dir_y * cos(rot_speed);
		double	old_plane_x = game->param.plane_x;
		game->param.plane_x = game->param.plane_x * cos(rot_speed) - game->param.plane_y * sin(rot_speed);
		game->param.plane_y = old_plane_x * sin(rot_speed) + game->param.plane_y * cos(rot_speed);
	}
	printf("%f %f\n", game->param.pos_x, game->param.pos_y);
	mlx_clear_window(game->mlx, game->win);
	main_loop(game);
	return (0);
}

int	press_exit_button(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free_game(game);
	printf("The End\n");
	exit(0);
	return (0);
}
