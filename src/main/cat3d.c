/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:00:23 by jisookim          #+#    #+#             */
/*   Updated: 2022/10/17 11:28:11 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cat3d.h"

int	main_loop(t_game *game)
{
	mouse_move(game);
	door(game);
	render(game);
	minimap(game);
	draw(game);
	key_update(game);
	return (0);
}

void	start_game(t_game *game)
{	
	init_param(game);
	set_buf_and_tex(game);
	game->mlx = mlx_init();
	load_texture(game);
	game->win = mlx_new_window(game->mlx, S_WIDTH, S_HEIGHT, "Cat3D");
	game->image.img = mlx_new_image(game->mlx, S_WIDTH, S_HEIGHT);
	game->image.data = (int *)mlx_get_data_addr(game->image.img, \
				&game->image.bpp, &game->image.size_l, &game->image.endian);
	mlx_loop_hook(game->mlx, &main_loop, game);
	mlx_hook(game->win, X_EVENT_EXIT_BUTTON, 0, &press_exit_button, game);
	mlx_hook(game->win, X_EVENT_PRESS_KEY, 0, &key_press, game);
	mlx_hook(game->win, X_EVENT_KEY_RELEASE, 0, &key_release, game);
	mlx_mouse_move(game->win, S_WIDTH / 2, S_HEIGHT / 2);
	mlx_mouse_hide();
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;

	init_game(&game);
	check_arg(argc, argv);
	parse_map(&game, argv[1]);
	start_game(&game);
	return (0);
}
