/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 03:07:35 by kyhan             #+#    #+#             */
/*   Updated: 2022/09/28 15:02:12 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cat3d.h"

static int	init_north(t_game *game, char *line, int *completed, char *gnl)
{
	int	i;

	if (*completed == 1)
		return (0);
	if (ft_strncmp(line, "NO", 2) || !is_space(line[2]))
		return (0);
	if (game->texture.north)
		return (1);
	i = 2;
	while (is_space(line[i]))
		i++;
	if (ft_strncmp(&line[i], "./", 2))
		return (1);
	game->texture.north = ft_strdup(&line[i]);
	open_texture(game, game->texture.north, gnl);
	*completed = 1;
	return (0);
}

static int	init_south(t_game *game, char *line, int *completed, char *gnl)
{
	int	i;

	if (*completed == 1)
		return (0);
	if (ft_strncmp(line, "SO", 2) || !is_space(line[2]))
		return (0);
	if (game->texture.south)
		return (1);
	i = 2;
	while (is_space(line[i]))
		i++;
	if (ft_strncmp(&line[i], "./", 2))
		return (1);
	game->texture.south = ft_strdup(&line[i]);
	open_texture(game, game->texture.south, gnl);
	*completed = 1;
	return (0);
}

static int	init_east(t_game *game, char *line, int *completed, char *gnl)
{
	int	i;

	if (*completed == 1)
		return (0);
	if (ft_strncmp(line, "EA", 2) || !is_space(line[2]))
		return (0);
	if (game->texture.east)
		return (1);
	i = 2;
	while (is_space(line[i]))
		i++;
	if (ft_strncmp(&line[i], "./", 2))
		return (1);
	game->texture.east = ft_strdup(&line[i]);
	open_texture(game, game->texture.east, gnl);
	*completed = 1;
	return (0);
}

static int	init_west(t_game *game, char *line, int *completed, char *gnl)
{
	int	i;

	if (*completed == 1)
		return (0);
	if (ft_strncmp(line, "WE", 2) || !is_space(line[2]))
		return (0);
	if (game->texture.west)
		return (1);
	i = 2;
	while (is_space(line[i]))
		i++;
	if (ft_strncmp(&line[i], "./", 2))
		return (1);
	game->texture.west = ft_strdup(&line[i]);
	open_texture(game, game->texture.west, gnl);
	*completed = 1;
	return (0);
}

int	init_texture(t_game *game, char *gnl, int *checked, int *map_flag)
{
	int	i;
	int	completed;

	i = 0;
	completed = 0;
	while (is_space(gnl[i]))
		i++;
	if (init_north(game, &gnl[i], &completed, gnl))
		return (1);
	if (init_south(game, &gnl[i], &completed, gnl))
		return (1);
	if (init_east(game, &gnl[i], &completed, gnl))
		return (1);
	if (init_west(game, &gnl[i], &completed, gnl))
		return (1);
	if (completed)
		*checked = 1;
	if (game->map.map && completed)
		*map_flag = 1;
	return (0);
}
