/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_release.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:45:48 by jisookim          #+#    #+#             */
/*   Updated: 2022/10/17 11:26:04 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cat3d.h"

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
	// if (keycode == KEY_M)
	// 	on_off_minimap(game);
	return (0);
}
