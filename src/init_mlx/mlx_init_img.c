/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:37:33 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/28 15:04:31 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cat3d.h"

static void	*make_image(t_game *game, char *file)
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
