/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 02:27:26 by kyhan             #+#    #+#             */
/*   Updated: 2022/09/28 16:22:02 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cat3d.h"

void	free_game(t_game *game)
{
	if (game->map.map)
		ft_free(game->map.map);
	if (game->texture.east)
		free(game->texture.east);
	if (game->texture.west)
		free(game->texture.west);
	if (game->texture.north)
		free(game->texture.north);
	if (game->texture.south)
		free(game->texture.south);
	if (game->rgb.ceiling)
		free(game->rgb.ceiling);
	if (game->rgb.floor)
		free(game->rgb.floor);
}
