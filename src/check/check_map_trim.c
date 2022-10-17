/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_trim.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 05:25:09 by kyhan             #+#    #+#             */
/*   Updated: 2022/10/17 11:24:36 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cat3d.h"

static void	add_space(t_game *game, int cnt)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (game->map.map[i])
	{
		j = ft_strlen(game->map.map[i]);
		while (j < cnt)
		{
			tmp = game->map.map[i];
			game->map.map[i] = ft_strjoin(tmp, " ");
			free(tmp);
			j++;
		}
		i++;
	}
}

void	trim_map_back(t_game *game)
{
	int	i;
	int	j;
	int	cnt;

	i = 0;
	cnt = 0;
	while (game->map.map[i])
	{
		j = ft_strlen_without_space(game->map.map[i]);
		if (cnt < j)
			cnt = j;
		i++;
	}
	add_space(game, cnt);
}

static void	del_space(t_game *game, int cnt)
{
	int	i;
	int	j;

	if (!cnt)
		return ;
	i = 0;
	while (game->map.map[i])
	{
		j = 0;
		while (j < cnt)
		{
			ft_strlcpy(&game->map.map[i][0], &game->map.map[i][1], \
						ft_strlen(game->map.map[i]));
			j++;
		}
		i++;
	}
}

void	trim_map_front(t_game *game)
{
	int	i;
	int	j;
	int	cnt;

	i = 0;
	while (game->map.map[i])
	{
		j = 0;
		while (game->map.map[i][j] == ' ')
			j++;
		if (!i)
			cnt = j;
		else if (cnt > j)
			cnt = j;
		i++;
	}
	del_space(game, cnt);
}
