/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyhan <kyhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:00:03 by jisookim          #+#    #+#             */
/*   Updated: 2022/10/19 09:45:56 by kyhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cat3d.h"

void	set_buf_and_tex(t_game *game)
{
	int	i;

	i = 0;
	game->tex = (int **)calloc(6, sizeof(int *));
	game->buf = (int **)calloc(S_HEIGHT, sizeof(int *));
	while (i < S_HEIGHT)
	{
		game->buf[i] = (int *)calloc(S_WIDTH, sizeof(int));
		i++;
	}
	i = 0;
	while (i < 6)
	{
		game->tex[i] = (int *)calloc((TEX_SIZE * TEX_SIZE), sizeof(int));
		i++;
	}
}

void	init_door(t_game *game)
{
	int	i;

	i = 0;
	game->open_door.door_offset = ft_calloc(game->map.height, sizeof(double *));
	game->open_door.door_state = ft_calloc(game->map.height, sizeof(int *));
	while (i < game->map.height)
	{
		game->open_door.door_offset[i] = ft_calloc(game->map.width, sizeof(double));
		game->open_door.door_state[i] = ft_calloc(game->map.width, sizeof(int));
		i++;
	}
}
