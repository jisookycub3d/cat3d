/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:00:03 by jisookim          #+#    #+#             */
/*   Updated: 2022/10/03 13:48:20 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cat3d.h"

void	start_game(t_game *game)
{
	// t_image	image;
	game->param.pos_x = game->player.pos_x;
	game->param.pos_y = game->player.pos_y; //플레이어 초기 위치벡터
	game->param.dir_x = -1;
	game->param.dir_y = 0; // 플레이어 초기 방향벡터
	game->param.plane_x = 0;
	game->param.plane_y = 0.66; //플레이어 카메라평면

	// init_image(game, &image);
	game->win = mlx_new_window(game->mlx, 640, 480, "Cat3D");
	// init_draw_obj(game, &image);
	mlx_loop_hook(game->mlx, &main_loop, game);
	mlx_hook(game->win, X_EVENT_EXIT_BUTTON, 0, &press_exit_button, game);
	mlx_hook(game->win, X_EVENT_PRESS_KEY, 0, &key_press, game);
	// mlx_mouse_hook(game->win, mouse_move, game);
	// mlx_loop_hook(game->mlx, move_player, game);
	mlx_loop(game->mlx);
}
