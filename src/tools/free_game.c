/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 02:27:26 by kyhan             #+#    #+#             */
/*   Updated: 2022/09/28 14:47:17 by jisookim         ###   ########.fr       */
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
