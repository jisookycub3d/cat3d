/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:34:42 by kyhan             #+#    #+#             */
/*   Updated: 2022/09/25 23:00:56 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cat3d.h"
#include "../include/param.h"
#include "../include/image.h"

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

void	*make_image(t_game *game, char *file)
{
	void	*img;
	int		width;
	int		height;
	
	img = mlx_png_file_to_image(game->mlx, file, &width, &height);
	return (img);
}

void	init_image(t_game *game, t_image *image)
{
	image->wall_n = make_image(game, game->texture.north);
// 	image->wall_s = make_image(game, game->texture.south);
// 	image->wall_w = make_image(game, game->texture.west);
// 	image->wall_e = make_image(game, game->texture.east);
}

void	start_game(t_game *game)
{
	t_param	param;
	t_image	image;

	init_param(&param);
	game->win = mlx_new_window(game->mlx, 2560, 1440, "jisookim");
	init_image(game, &image);
	mlx_put_image_to_window(game->mlx, game->win, image.wall_n, 50, 50);
	mlx_hook(game->win, 2, 0, key_press, &param);
	mlx_loop(game->mlx);
}