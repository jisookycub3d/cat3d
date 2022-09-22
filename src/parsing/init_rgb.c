/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rgb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 03:10:20 by kyhan             #+#    #+#             */
/*   Updated: 2022/09/23 03:21:37 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cat3d.h"

int	get_rgb(t_game *game, char *line)
{
	int		i;
	char	**rgb;
	char	flag;

	i = 0;
	if (line[0] == 'C')
		flag = 'C';
	else
		flag = 'F';
	line++;
	while (*line == ' ')
		line++;
	rgb = ft_split(line, ',');
	while (rgb[i])
		i++;
	if (i != 3)
		return (1);
	if (rgb_atoi(game, rgb, flag))
	{
		ft_free(rgb);
		return(1);
	}
	ft_free(rgb);
	return (0);
}

int	init_ceiling(t_game *game, char *line, int *complited)
{
	if (*complited == 1)
		return (0);
	if (ft_strncmp(line, "C ", 2))
		return (0);
	if (game->rgb.ceiling)
		return (1);
	if (get_rgb(game, line))
	{
		free(game->rgb.ceiling);
		return (1);
	}
	*complited = 1;
	return (0);
}

int	init_floor(t_game *game, char *line, int *complited)
{
	if (*complited == 1)
		return (0);
	if (ft_strncmp(line, "F ", 2))
		return (0);
	if (game->rgb.floor)
		return (1);
	if (get_rgb(game, line))
	{
		free(game->rgb.floor);
		return (1);
	}
	*complited = 1;
	return (0);
}

int	init_rgb(t_game *game, char *gnl, int *checked, int *map_flag)
{
	int	i;
	int	completed;

	i = 0;
	completed = 0;
	while (gnl[i] == ' ')
		i++;
	if (init_ceiling(game, &gnl[i], &completed))
		return (1);
	if (init_floor(game, &gnl[i], &completed))
		return (1);
	if (completed)
		*checked = 1;
	if (game->map.map && completed)
		*map_flag = 1;
	return (0);
}
