/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:35:51 by jisookim          #+#    #+#             */
/*   Updated: 2022/09/28 14:59:39 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cat3d.h"

static int	check_right_direct(t_game *game)
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
				if (get_direct_pos(game, game->map.map[i][j], i, j))
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

static int	check_right_composition(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.map[i])
	{
		j = 0;
		while (game->map.map[i][j])
		{
			if ((ft_strchr("NSEW10D ", game->map.map[i][j])))
				bit_mask(&game->map.map[i][j]);
			else
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_full(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.map[i])
	{
		j = 0;
		while (game->map.map[i][j])
		{
			if (!(game->map.map[i][j] & WALL) && !(game->map.map[i][j] & SPACE))
				if (check_wall(game, i, j))
					return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_content(t_game *game)
{
	if (check_right_direct(game))
		return (1);
	if (check_right_composition(game))
		return (1);
	if (check_full(game))
		return (1);
	return (0);
}
