/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:34:42 by kyhan             #+#    #+#             */
/*   Updated: 2022/09/24 20:31:27 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cat3d.h"
#include "../include/param.h"

int	key_press(int keycode, t_param *param)
{
	if (keycode == KEY_ESC)
	{
		printf("The End\n");
		exit(0);
	}
	if (keycode == KEY_A)
		param->x--;
	if (keycode == KEY_D)
		param->x++;
	if (keycode == KEY_S)
		param->y--;
	if (keycode == KEY_W)
		param->y++;
	return (0);
}

void	start_game(t_game *game)
{
	t_param	param;

	init_param(&param);
	game->win = mlx_new_window(game->mlx, 2560, 1440, "jisookim");
	mlx_pixel_put(game->mlx, game->win, param.x, param.y, 500);
	mlx_hook(game->win, 2, 0, key_press, &param);
	mlx_loop(game->mlx);
}