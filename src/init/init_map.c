/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 03:17:04 by kyhan             #+#    #+#             */
/*   Updated: 2022/10/17 11:24:54 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cat3d.h"

static int	init_check_gnl_in_map(char *gnl, int *checked, int *map_flag)
{
	int	i;

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
		return (-1);
	return (1);
}

static void	do_map_append(t_game *game, char *line)
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

static void	init_set_map(t_game *game, char *line)
{
	if (!game->map.map)
	{
		game->map.map = ft_calloc(2, sizeof(char *));
		game->map.map[0] = line;
		game->map.map[1] = 0;
	}
	else
		do_map_append(game, line);
}

int	init_map(t_game *game, char *gnl, int *checked, int *map_flag)
{
	int		ret;
	char	*line;

	ret = 0;
	ret = init_check_gnl_in_map(gnl, checked, map_flag);
	if (ret == -1)
		return (1);
	else if (!ret)
		return (0);
	line = ft_strdup(gnl);
	init_set_map(game, line);
	return (0);
}
