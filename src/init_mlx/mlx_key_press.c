/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_press.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:09:22 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/28 15:11:47 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cat3d.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_A)
	{
		mlx_pixel_put(game->mlx, game->win, game->player.pos_x, game->player.pos_y, rgb_to_i(game->rgb.floor));
		game->player.pos_x--;
		mlx_pixel_put(game->mlx, game->win, game->player.pos_x, game->player.pos_y, 255);
	}
	if (keycode == KEY_D)
	{
		mlx_pixel_put(game->mlx, game->win, game->player.pos_x, game->player.pos_y, rgb_to_i(game->rgb.floor));
		game->player.pos_x++;
		mlx_pixel_put(game->mlx, game->win, game->player.pos_x, game->player.pos_y, 255);
	}
	if (keycode == KEY_S)
	{
		mlx_pixel_put(game->mlx, game->win, game->player.pos_x, game->player.pos_y, rgb_to_i(game->rgb.floor));
		game->player.pos_y--;
		mlx_pixel_put(game->mlx, game->win, game->player.pos_x, game->player.pos_y, 255);
	}
	if (keycode == KEY_W)
	{
		mlx_pixel_put(game->mlx, game->win, game->player.pos_x, game->player.pos_y, rgb_to_i(game->rgb.floor));
		game->player.pos_y++;
		mlx_pixel_put(game->mlx, game->win, game->player.pos_x, game->player.pos_y, 255);
	}
	return (0);
}

int	press_exit_button(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
	{
		free_game(game);
		// mlx_destroy_window(game->mlx, game->win);
		printf("The End\n");
		exit(0);
	}
	return (0);
}
