/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisookim <jisookim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:40:52 by jisookim          #+#    #+#             */
/*   Updated: 2022/10/17 11:46:51 by jisookim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cat3d.h"

char	bit_mask(t_game *game, char c)
{
	if (c == '1')
		c = WALL;
	else if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		c = EMPTY;
	else if (c == ' ')
		c = SPACE;
	else if (c == 'D')
		c = DOOR;
	else if (c == '2')
	{
		c = SPRITE;
		game->sprite_cnt++;
	}
	return (c);
}
