/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:00:03 by jisookim          #+#    #+#             */
/*   Updated: 2022/10/17 11:26:28 by jisookim         ###   ########.fr       */
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
