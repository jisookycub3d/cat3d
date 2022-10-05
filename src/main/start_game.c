/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:00:03 by jisookim          #+#    #+#             */
/*   Updated: 2022/10/05 18:03:03 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cat3d.h"

void	start_game(t_game *game)
{
	game->param.pos_x = (double)(game->player.pos_x) + 0.5;
	game->param.pos_y = (double)(game->player.pos_y) + 0.5; //플레이어 초기 위치벡터
	game->param.dir_x = -1;
	game->param.dir_y = 0; // 플레이어 초기 방향벡터
	game->param.plane_x = 0;
	game->param.plane_y = 0.66; //플레이어 카메라평면
	
	game->tex = (int **)malloc(sizeof(int *) * 6);
	game->map.buf = (int **)malloc(sizeof(int *) * S_HEIGHT);
	for(int i = 0; i < S_HEIGHT; i++)
	{
		game->map.buf[i] = (int *)malloc(sizeof(int) * S_WIDTH);
	}
	for(int i = 0; i < S_HEIGHT; i++)
	{
		for(int j = 0; j < S_WIDTH; j++)
			game->map.buf[i][j] = EMPTY;
	}
	for (int i = 0; i < 6; i++)
	{
		game->tex[i] = (int *)malloc(sizeof(int) * (TEX_SIZE * TEX_SIZE));
	}
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < (TEX_SIZE * TEX_SIZE); j++)
		{
			game->tex[i][j] = 0;
		}
	}

	// init_image(game, &image);
	game->mlx = mlx_init();
	load_texture(game);
	game->win = mlx_new_window(game->mlx, S_WIDTH, S_HEIGHT, "Cat3D");
	game->image.img = mlx_new_image(game->mlx, S_WIDTH, S_HEIGHT);
	game->image.data = (int *)mlx_get_data_addr(game->image.img, &game->image.bpp, &game->image.size_l, &game->image.endian);
	// init_draw_obj(game, &image);

	mlx_loop_hook(game->mlx, &main_loop, game);
	mlx_hook(game->win, X_EVENT_EXIT_BUTTON, 0, &press_exit_button, game);
	mlx_hook(game->win, X_EVENT_PRESS_KEY, 0, &key_press, game);
	// mlx_mouse_hook(game->win, mouse_move, game);
	// mlx_loop_hook(game->mlx, move_player, game);
	mlx_loop(game->mlx);
}
