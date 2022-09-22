/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 05:22:12 by kyhan             #+#    #+#             */
/*   Updated: 2022/09/23 05:56:12 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cat3d.h"

int	check_full(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.map[i])
	{
		j = 0;
		while (game->map.map[i][j] == ' ')
			j++;
		while (game->map.map[i][j] && game->map.map[i][j] != ' ')
		{
			if (!ft_strchr("NSEW10D", game->map.map[i][j]))
				return (1);
			j++;
		}
		while (game->map.map[i][j] == ' ')
			j++;
		if (game->map.map[i][j])
			return (1);
		i++;
	}
	return (0);
}

int	check_right_composition(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.map[i])
	{
		j = 0;
		while (game->map.map[i][j])
		{
			if (ft_strchr("NSEW", game->map.map[i][j]))
			{
				if (!game->player.direction)
					game->player.direction = game->map.map[i][j];
				else
					return (1);
			}
			j++;
		}
		i++;
	}
	if (!game->player.direction)
		return (1);
	return (0);
}

int	check_composition(t_game *game)
{
	if (check_full(game))
		return (1);
	if (check_right_composition(game))
		return (1);
	return (0);
}

int	check_row(t_game *game)
{
	int	i;
	int	j;
	int	front;
	int	back;

	i = 0;
	j = ft_strlen(game->map.map[i]) - 1;
	while (game->map.map[i])
	{
		front = 0;
		back = j;
		while (game->map.map[i][front] == ' ')
			front++;
		while (game->map.map[i][back] == ' ')
			back--;
		if (!(game->map.map[i][front] == '1' && game->map.map[i][back] == '1'))
			return (1);
		i++;
	}
	return (0);
}

int	check_col(t_game *game)
{
	int	i;
	int	j;
	int	col_idx;
	int	row_len;
	int	col_len;

	i = 0;
	j = ft_strslen(game->map.map) - 1;
	row_len = ft_strlen(game->map.map[i]);
	while (i < row_len)
	{
		col_idx = 0;
		col_len = j;
		while (game->map.map[col_idx][i] == ' ')
			col_idx++;
		while (game->map.map[col_len][i] == ' ')
			col_len--;
		if (!(game->map.map[col_idx][i] == '1' && game->map.map[col_len][i] == '1'))
			return (1);
		i++;
	}
	return (0);
}

int	check_map(t_game *game)
{
	char	**map;
	int		i;

	if (!game->map.map)
		return (1);
	i = ft_strslen(game->map.map);
	if (i < 3)
		return (1);
	i = 0;
	map = game->map.map;
	trim_map_front(game);
	trim_map_back(game);
	if (check_row(game))
		return (1);
	if (check_col(game))
		return (1);
	if (check_composition(game))
		return (1);
	return (0);
}
