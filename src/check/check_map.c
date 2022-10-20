/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 05:22:12 by kyhan             #+#    #+#             */
/*   Updated: 2022/10/17 11:23:27 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cat3d.h"

int	check_wall(t_game *game, int i, int j)
{
	int	row_len;
	int	col_len;
	int	cnt;

	row_len = ft_strlen(game->map.map[i]) - 1;
	col_len = ft_strslen(game->map.map) - 1;
	if (((i != col_len && (game->map.map[i + 1][j] & SPACE)) || i == col_len))
		return (1);
	if (((i && (game->map.map[i - 1][j] & SPACE)) || i == 0))
		return (1);
	if (((j != row_len && (game->map.map[i][j + 1] & SPACE)) || j == row_len))
		return (1);
	if (((j && (game->map.map[i][j - 1] & SPACE)) || j == 0))
		return (1);
	if (game->map.map[i][j] & DOOR)
	{
		cnt = 0;
		if (game->map.map[i - 1][j] & WALL && game->map.map[i + 1][j] & WALL)
			cnt++;
		if (game->map.map[i][j - 1] & WALL && game->map.map[i][j + 1] & WALL)
			cnt++;
		if (!cnt)
			return (1);
	}
	return (0);
}

int	get_direct_pos(t_game *game, char c, int i, int j)
{
	if (!game->player.direction)
	{
		game->player.direction = c;
		game->player.pos_x = j;
		game->player.pos_y = i;
	}
	else
		return (1);
	return (0);
}

int	check_map(t_game *game)
{
	int		i;

	if (!game->map.map)
		return (1);
	i = ft_strslen(game->map.map);
	if (i < 3)
		return (1);
	trim_map_front(game);
	trim_map_back(game);
	if (check_content(game))
		return (1);
	return (0);
}
