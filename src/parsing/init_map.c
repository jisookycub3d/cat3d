/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 03:17:04 by kyhan             #+#    #+#             */
/*   Updated: 2022/09/23 03:21:33 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cat3d.h"

void	make_map(t_game *game, char *line)
{
	int		i;
	int		j;
	char	**strs;
	char	**tmp;

	i = 0;
	j = 0;
	while (game->map.map[i])
		i++;
	strs = ft_calloc(i + 2, sizeof(char *));
	while (j < i)
	{
		strs[j] = game->map.map[j];
		j++;
	}
	strs[j] = line;
	tmp = game->map.map;
	game->map.map = strs;
	free(tmp);
}

int	init_map(t_game *game, char *gnl, int *checked, int *map_flag)
{
	int		i;
	char	*line;

	i = 0;
	if (*checked == 1)
		return (0);
	while (gnl[i] == ' ')
		i++;
	if (gnl[i] == '1')
		*checked = 1;
	else
		return (0);
	if (*map_flag)
		return (1);
	line = ft_strdup(gnl);
	if (!game->map.map)
	{
		game->map.map = ft_calloc(2, sizeof(char *));
		game->map.map[0] = line;
		game->map.map[1] = 0;
	}
	else
		make_map(game, line);
	return (0);
}
