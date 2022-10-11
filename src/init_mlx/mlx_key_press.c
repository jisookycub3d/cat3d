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

void	key_update(t_game *game)
{
    double	move_speed = 0.07;
    double	rot_speed = 0.1;
    double  old_dir_x;
    double  old_plane_x;

    if (game->keycode.key_a)
    {
        if (game->map.imap[(int)(game->param.pos_y)][(int)(game->param.pos_x + game->param.plane_x * move_speed)] & EMPTY)
            game->param.pos_x += game->param.plane_x * move_speed;
        if (game->map.imap[(int)(game->param.pos_y + game->param.plane_y * move_speed)][(int)(game->param.pos_x)] & EMPTY)
            game->param.pos_y += game->param.plane_y * move_speed;
    }
    if (game->keycode.key_d)
    {
        if (game->map.imap[(int)(game->param.pos_y)][(int)(game->param.pos_x - game->param.plane_x * move_speed)] & EMPTY)
            game->param.pos_x -= game->param.plane_x * move_speed;
        if (game->map.imap[(int)(game->param.pos_y - game->param.plane_y * move_speed)][(int)(game->param.pos_x)] & EMPTY)
            game->param.pos_y -= game->param.plane_y * move_speed;
    }
    if (game->keycode.key_s)
    {
        if (game->map.imap[(int)(game->param.pos_y)][(int)(game->param.pos_x - game->param.dir_x * move_speed)] & EMPTY)
            game->param.pos_x -= game->param.dir_x * move_speed;
        if (game->map.imap[(int)(game->param.pos_y - game->param.dir_y * move_speed)][(int)(game->param.pos_x)] & EMPTY)
            game->param.pos_y -= game->param.dir_y * move_speed;
    }
    if (game->keycode.key_w)
    {
        if (game->map.imap[(int)(game->param.pos_y)][(int)(game->param.pos_x + game->param.dir_x * move_speed)] & EMPTY)
            game->param.pos_x += game->param.dir_x * move_speed;
        if (game->map.imap[(int)(game->param.pos_y + game->param.dir_y * move_speed)][(int)(game->param.pos_x)] & EMPTY)
            game->param.pos_y += game->param.dir_y * move_speed;
    }
    if (game->keycode.key_left)
    {
        old_dir_x = game->param.dir_x;
        game->param.dir_x = game->param.dir_x * cos(-rot_speed) - game->param.dir_y * sin(-rot_speed);
        game->param.dir_y = old_dir_x * sin(-rot_speed) + game->param.dir_y * cos(-rot_speed);
        old_plane_x = game->param.plane_x;
        game->param.plane_x = game->param.plane_x * cos(-rot_speed) - game->param.plane_y * sin(-rot_speed);
        game->param.plane_y = old_plane_x * sin(-rot_speed) + game->param.plane_y * cos(-rot_speed);
    }
    if (game->keycode.key_right)
    {
        old_dir_x = game->param.dir_x;
        game->param.dir_x = game->param.dir_x * cos(rot_speed) - game->param.dir_y * sin(rot_speed);
        game->param.dir_y = old_dir_x * sin(rot_speed) + game->param.dir_y * cos(rot_speed);
        old_plane_x = game->param.plane_x;
        game->param.plane_x = game->param.plane_x * cos(rot_speed) - game->param.plane_y * sin(rot_speed);
        game->param.plane_y = old_plane_x * sin(rot_speed) + game->param.plane_y * cos(rot_speed);
    }
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
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		 press_exit_button(game);
	if (keycode == KEY_A)
		game->keycode.key_a = 0;
	if (keycode == KEY_W)
		game->keycode.key_w = 0;
	if (keycode == KEY_D)
		game->keycode.key_d = 0;
	if (keycode == KEY_S)
		game->keycode.key_s = 0;
	if (keycode == KEY_LEFT)
		game->keycode.key_left = 0;
	if (keycode == KEY_RIGHT)
		game->keycode.key_right = 0;
	if (keycode == KEY_E)
	{
		if (game->map.imap[(int)floor(game->param.pos_y)][(int)floor(game->param.pos_x) + 1] & DOOR)
			game->door = 1;
		if (game->map.imap[(int)floor(game->param.pos_y)][(int)floor(game->param.pos_x) + 1] & DOOR)
			game->door = 1;
		if (game->map.imap[(int)floor(game->param.pos_y) + 1][(int)floor(game->param.pos_x)] & DOOR)
			game->door = 1;
		if (game->map.imap[(int)floor(game->param.pos_y) - 1][(int)floor(game->param.pos_x)] & DOOR)
			game->door = 1;
	}
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
