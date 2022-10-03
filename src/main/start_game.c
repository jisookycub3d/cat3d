/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:00:03 by jisookim          #+#    #+#             */
/*   Updated: 2022/10/03 23:18:38 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cat3d.h"

void	start_game(t_game *game)
{
	// t_image	image;
	game->param.pos_x = 22.0;
	game->param.pos_y = 11.5; //플레이어 초기 위치벡터
	game->param.dir_x = -1;
	game->param.dir_y = 0; // 플레이어 초기 방향벡터
	game->param.plane_x = 0;
	game->param.plane_y = 0.66; //플레이어 카메라평면
	
	game->map.buf = (int **)malloc(sizeof(int *) * 480);
	for(int i = 0; i < 480; i++)
	{
		game->map.buf[i] = (int *)malloc(sizeof(int) * 640);
	}
	for(int i = 0; i < 480; i++)
	{
		for(int j = 0; j < 640; j++)
			game->map.buf[i][j] = EMPTY;
	}
	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 64 * 64; j++)
			game->map.tex[i][j] = 0;
	}
	for (int x = 0; x < 64; x++)
	{
		for (int y = 0; y < 64; y++)
		{
			int xorcolor = (x * 256 / 64) ^ (y * 256 / 64);
			int ycolor = y * 256 / 64;
			int xycolor = y * 128 / 64 + x * 128 / 64;
			game->map.tex[0][64 * y + x] = 65536 * 254 * (x != y && x != 64 - y); //flat red texture with black cross
			game->map.tex[1][64 * y + x] = xycolor + 256 * xycolor + 65536 * xycolor; //sloped greyscale
			game->map.tex[2][64 * y + x] = 256 * xycolor + 65536 * xycolor; //sloped yellow gradient
			game->map.tex[3][64 * y + x] = xorcolor + 256 * xorcolor + 65536 * xorcolor; //xor greyscale
			game->map.tex[4][64 * y + x] = 256 * xorcolor; //xor green
			game->map.tex[5][64 * y + x] = 65536 * 192 * (x % 16 && y % 16); //red bricks
			game->map.tex[6][64 * y + x] = 65536 * ycolor; //red gradient
			game->map.tex[7][64 * y + x] = 128 + 256 * 128 + 65536 * 128; //flat grey texture
		}
	}

	// init_image(game, &image);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 640, 480, "Cat3D");
	game->image.wall_w = mlx_new_image(game->mlx, 640, 480);
	game->image.data = (int *)mlx_get_data_addr(game->image.wall_w, &game->image.bpp, &game->image.size_l, &game->image.endian);
	// init_draw_obj(game, &image);
	main_loop(game);
	// mlx_loop_hook(game->mlx, &main_loop, game);
	mlx_hook(game->win, X_EVENT_EXIT_BUTTON, 0, &press_exit_button, game);
	mlx_hook(game->win, X_EVENT_PRESS_KEY, 0, &key_press, game);
	// mlx_mouse_hook(game->win, mouse_move, game);
	// mlx_loop_hook(game->mlx, move_player, game);
	mlx_loop(game->mlx);
}
