/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 05:22:12 by kyhan             #+#    #+#             */
/*   Updated: 2022/10/03 13:00:45 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cat3d.h"

int	check_wall(t_game *game, int i, int j)
{
	int	row_len;
	int	col_len;

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
	return (0);
}

int	get_direct_pos(t_game *game, char c, int i, int j)
{
	if (!game->player.direction)
	{
		game->player.direction = c;
		game->player.pos_x = i;
		game->player.pos_y = j;
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
	i = 0;
	for(int i = 0; game->map.map[i]; i++)
	{
		printf("%s\n", game->map.map[i]);
	}
	trim_map_front(game);
	trim_map_back(game);
	if (check_content(game))
		return (1);
	return (0);
}
