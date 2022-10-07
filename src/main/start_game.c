/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:00:03 by jisookim          #+#    #+#             */
/*   Updated: 2022/10/07 09:34:51 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cat3d.h"

void	init_param_dir(t_game *game)
{
	if (game->player.direction == 'N')
	{
		game->param.dir_x = 0;
		game->param.dir_y = -1;
	}
	else if (game->player.direction == 'S')
	{
		game->param.dir_x = 0;
		game->param.dir_y = 1;
	}
	else if (game->player.direction == 'W')
	{
		game->param.dir_x = 1;
		game->param.dir_y = 0;
	}
	else if (game->player.direction == 'E')
	{
		game->param.dir_x = -1;
		game->param.dir_y = 0;
	}
}

void init_param(t_game *game)
{
	game->param.pos_x = (double)(game->player.pos_x) + 0.5;
	game->param.pos_y = (double)(game->player.pos_y) + 0.5; //플레이어 초기 위치벡터
    init_param_dir(game);
	if (game->param.dir_x < 0)
		game->param.plane_y = 0.66;
	else if (game->param.dir_x > 0)
		game->param.plane_y = -0.66;
	else if (game->param.dir_y < 0)
		game->param.plane_x = -0.66;
	else if (game->param.dir_y > 0)
		game->param.plane_x = 0.66;
	game->rgb.floor_rgb = rgb_to_i(game->rgb.floor);
	game->rgb.ceiling_rgb = rgb_to_i(game->rgb.ceiling);
}

void	set_buf_and_tex(t_game *game)
{
	int	i;

	i = 0;
	game->tex = (int **)calloc(6, sizeof(int *));
	game->buf = (int **)calloc(S_HEIGHT, sizeof(int *));
	while (i < S_HEIGHT)
	{
		game->buf[i] = (int *)calloc(S_WIDTH, sizeof(int));
		i++;
	}
	i = 0;
	while (i < 6)
	{
		game->tex[i] = (int *)calloc((TEX_SIZE * TEX_SIZE), sizeof(int));
		i++;
	}
}

void	start_game(t_game *game)
{	
	init_param(game);
	set_buf_and_tex(game);
	game->mlx = mlx_init();
	load_texture(game);
	game->win = mlx_new_window(game->mlx, S_WIDTH, S_HEIGHT, "Cat3D");
	game->image.img = mlx_new_image(game->mlx, S_WIDTH, S_HEIGHT);
	game->image.data = (int *)mlx_get_data_addr(game->image.img, &game->image.bpp, &game->image.size_l, &game->image.endian);
	mlx_loop_hook(game->mlx, &main_loop, game);
	mlx_hook(game->win, X_EVENT_EXIT_BUTTON, 0, &press_exit_button, game);
	mlx_hook(game->win, X_EVENT_PRESS_KEY, 0, &key_press, game);
	// mlx_mouse_hook(game->win, mouse_move, game);
	mlx_loop(game->mlx);
}
