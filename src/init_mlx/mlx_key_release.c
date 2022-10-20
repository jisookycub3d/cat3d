/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_release.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:45:48 by jisookim          #+#    #+#             */
/*   Updated: 2022/10/20 21:28:44 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cat3d.h"

void	toggle_minimap(t_game *game)
{
	if (game->minimap)
		game->minimap = 0;
	else
		game->minimap = 1;
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
		press_key_e(game);
	if (keycode == KEY_SHIFT)
		game->keycode.key_shift = 0;
	if (keycode == KEY_M)
		toggle_minimap(game);
	return (0);
}
