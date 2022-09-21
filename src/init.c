/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 02:28:13 by kyhan             #+#    #+#             */
/*   Updated: 2022/09/21 21:53:26 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cat3d.h"

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->map.map = 0;
	game->texture.east = 0;
	game->texture.north = 0;
	game->texture.south = 0;
	game->texture.west = 0;
}
