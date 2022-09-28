/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:34:42 by kyhan             #+#    #+#             */
/*   Updated: 2022/09/24 21:28:28 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cat3d.h"
#include "../include/param.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
	{
		printf("The End\n");
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	if (keycode == KEY_A)
		game->param.x--;
	if (keycode == KEY_D)
		game->param.x++;
	if (keycode == KEY_S)
		game->param.y--;
	if (keycode == KEY_W)
		game->param.y++;
	return (0);
}

void	start_game(t_game *game)
{
	game->win = mlx_new_window(game->mlx, 2560, 1440, "jisookim");

	mlx_hook(game->win, 2, 0, key_press, &game);
	mlx_loop(game->mlx);
}