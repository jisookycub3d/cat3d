/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 02:28:13 by kyhan             #+#    #+#             */
/*   Updated: 2022/10/17 11:24:20 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cat3d.h"

int	init_content(t_game *game, char *gnl)
{
	int			i;
	int			checked;
	static int	map_flag;

	i = 0;
	checked = 0;
	while (is_space(gnl[i]))
		i++;
	if (gnl[i] == '\0')
	{
		if (game->map.map)
			map_flag = 1;
		return (0);
	}
	if (init_texture(game, gnl, &checked, &map_flag))
		return (1);
	if (init_map(game, gnl, &checked, &map_flag))
		return (1);
	if (init_rgb(game, gnl, &checked, &map_flag))
		return (1);
	if (!checked)
		return (1);
	return (0);
}

void	init_game(t_game *game)
{
	ft_memset(game, 0, sizeof(t_game));
}
