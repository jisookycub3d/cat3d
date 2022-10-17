/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:08:03 by jisookim          #+#    #+#             */
/*   Updated: 2022/10/17 11:55:26 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cat3d.h"

void	door(t_game *game)
{
	int	map_y;
	int	map_x;

	map_x = (int)floor(game->param.pos_x);
	map_y = (int)floor(game->param.pos_y);
	if (!game->door)
		return ;
	if (game->map.imap[map_y][map_x + 1] & DOOR)
		game->map.imap[map_y][map_x + 1] = EMPTY;
	if (game->map.imap[map_y][map_x - 1] & DOOR)
		game->map.imap[map_y][map_x - 1] = EMPTY;
	if (game->map.imap[map_y + 1][map_x] & DOOR)
		game->map.imap[map_y + 1][map_x] = EMPTY;
	if (game->map.imap[map_y - 1][map_x] & DOOR)
		game->map.imap[map_y - 1][map_x] = EMPTY;
	game->door = 0;
}
