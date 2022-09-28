/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 03:14:28 by kyhan             #+#    #+#             */
/*   Updated: 2022/09/28 15:00:10 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cat3d.h"

static int	 check_texture(t_game *game)
{
	if (game->texture.east && game->texture.west 
		&& game->texture.north && game->texture.south)
		return (0);
	return (1);
}

static int	check_rgb(t_game *game)
{
	if (game->rgb.ceiling && game->rgb.floor)
		return (0);
	return (1);
}

int	check_valid(t_game *game)
{
	if (check_texture(game))
		return (1);
	if (check_map(game))
		return (1);
	if (check_rgb(game))
		return (1);
	return (0);
}
