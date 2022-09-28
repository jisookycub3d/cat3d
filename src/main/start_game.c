/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:00:03 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/28 16:43:51 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cat3d.h"

void	start_game(t_game *game)
{
	t_image	image;

	game->win = mlx_new_window(game->mlx, 2560, 1440, "Cat3D");
	init_image(game, &image);
	init_draw_obj(game, &image);
	mlx_hook(game->win, X_EVENT_EXIT_BUTTON, 0, press_exit_button, game);
	mlx_hook(game->win, X_EVENT_PRESS_KEY, 0, key_press, game);
	// mlx_loop_hook(game->mlx, move_player, game);
	mlx_loop(game->mlx);
}
