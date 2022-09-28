/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:34:42 by kyhan             #+#    #+#             */
/*   Updated: 2022/09/28 09:48:48 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cat3d.h"
#include "../include/param.h"
#include "../include/image.h"
#include "../include/parse.h"

int	rgb_to_i(int *arr)
{
	return (arr[0] * 16 * 16 * 16 * 16 + arr[1] * 16 * 16 + arr[2]);
}

int	move_player(t_game *game)
{
	mlx_pixel_put(game->mlx, game->win, game->player.pos_x, game->player.pos_y, rgb_to_i(game->rgb.floor));
	mlx_pixel_put(game->mlx, game->win, game->player.pos_x, game->player.pos_y, 255);
	return (0);
}

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
	// image->wall_s = make_image(game, game->texture.south);
	// image->wall_w = make_image(game, game->texture.west);
	// image->wall_e = make_image(game, game->texture.east);
}

void	draw_floor(t_game *game)
{
	int	i;
	int	j;
	int	rgb;

	i = 0;
	rgb = rgb_to_i(game->rgb.floor);
	while (i < 2560)
	{
		j = 0;
		while (j < 1440)
		{
			mlx_pixel_put(game->mlx, game->win, i, j, rgb);
			j++;
		}
		i++;
	}
}

void	draw_wall(t_game *game, t_image *image)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.map[i])
	{
		j = 0;
		while (game->map.map[i][j])
		{
			if (game->map.map[i][j] & WALL)
			{
				printf ("%d, %d\n", i, j);
				mlx_put_image_to_window(game->mlx, game->win, image->wall_n, j * 64, i * 64);
			}
			j++;
		}
		i++;
	}
}

void	draw_player(t_game *game)
{
	mlx_pixel_put(game->mlx, game->win, game->player.pos_x, game->player.pos_y, 255);
}

void	start_game(t_game *game)
{
	t_image	image;

	game->win = mlx_new_window(game->mlx, 2560, 1440, "jisookim");
	init_image(game, &image);
	draw_floor(game);
	draw_wall(game, &image);
	draw_player(game);
	mlx_hook(game->win, 2, 0, key_press, &game);
	// mlx_loop_hook(game->mlx, move_player, game);
	mlx_loop(game->mlx);
}