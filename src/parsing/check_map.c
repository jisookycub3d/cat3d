/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 05:22:12 by kyhan             #+#    #+#             */
/*   Updated: 2022/09/24 14:31:57 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cat3d.h"
#include "../../include/parse.h"

int	check_wall(t_game *game, int i, int j)
{
	int	row_len;
	int	col_len;

	row_len = ft_strlen(game->map.map[i]) - 1;
	col_len = ft_strslen(game->map.map) - 1;
	if (((i != col_len && (game->map.map[i + 1][j] & SPACE)) || i == col_len))
		return (1);
	if (((!i && (game->map.map[i - 1][j] & SPACE)) || i == 0))
		return (1);
	if (((j != row_len && (game->map.map[i][j + 1] & SPACE)) || j == row_len))
		return (1);
	if (((!j && (game->map.map[i][j - 1] & SPACE)) || j == 0))
		return (1);
	return (0);
}

int	check_full(t_game *game)
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

int	check_right_direct(t_game *game)
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

void	bit_mask(char *c)
{
	if (*c == '1')
		*c = WALL;
	else if (*c == 'N' || *c == 'S' || *c == 'E' || *c == 'W')
		*c = DIRECTION;
	else if (*c == ' ')
		*c = SPACE;
	else if (*c == '0')
		*c = EMPTY;
	else if (*c == 'D')
		*c = DOOR;
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

int	check_composition(t_game *game)
{
	if (check_right_direct(game))
		return (1);
	if (check_right_composition(game))
		return (1);
	if (check_full(game))
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
	trim_map_front(game);
	trim_map_back(game); 

	int a = 0;
	while (game->map.map[a])
	{
		printf("%d|", a);
		printf("%s$\n", game->map.map[a]);
		a++;
	}
	if (check_composition(game))
		return (1);
	return (0);
}
